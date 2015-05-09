#include <config.h>

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <syslog.h>
#include <pwd.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include <oidentd.h>
#include <oidentd_util.h>
#include <oidentd_missing.h>
#include <oidentd_inet_util.h>
#include <oidentd_user_db.h>
#include <oidentd_options.h>
#include <oidentd_user_request.h>

struct host_port_t {
	char *host;
	int   port;
};

struct split_result_t {
	char **result;
	int len;
};

struct split_result_t* split_str(char* input, char delim) {
	char *work_freeable, *work_str, *pch;
	work_str = work_freeable = strdup(input); //Because strsep modifies the string

	struct split_result_t *rc = (struct split_result_t *)xmalloc(sizeof(struct split_result_t));
	rc->len = 0;
	rc->result = (char**)xmalloc(0);

	char delim_str[2] = { delim, 0x0 };

	while ((pch = strsep(&work_str, delim_str)) != NULL) {
		rc->len = rc->len + 1;
		rc->result = (char**)xrealloc(rc->result, (rc->len) * sizeof(char*));
		rc->result[rc->len-1] = strdup(pch);
	}

	free(work_freeable);

	return rc;
}

void split_free(struct split_result_t *in) {
	if (!in)
		return;
	int i;
	for (i = 0; i < in->len; i++)
		if (in->result[i])
			free(in->result[i]);
	free(in);
}

struct host_port_t* parse_host(char* line) {
	struct host_port_t* rc = xmalloc(sizeof(struct host_port_t));
	rc->host = (char*)xmalloc(1);
	rc->host[0] = 0x0;

	struct split_result_t* splitted = split_str(line, ':');

	rc->port = atoi(splitted->result[splitted->len-1]);

	int i;
	for (i = 0; i < splitted->len-1; i++) { //it's len-1 so we ignore the port when concatting
		int isLastToken = i == splitted->len-2;
		rc->host = (char*)xrealloc(rc->host, strlen(rc->host)+strlen(splitted->result[i])+((isLastToken)?0:1));
		strcat(rc->host, splitted->result[i]);
		if (!isLastToken)
			strcat(rc->host, ":");
	}

	//Make sure to free everything
	split_free(splitted);

	return rc;
}

void host_free(struct host_port_t *in) {
	if (!in)
		return;
	if (in->host)
		free(in->host);
	free(in);
}

//WARNING: I suck at C sockets. They give me headaches.

struct sockaddr_storage* to_sockaddr(const char *addr, const unsigned short int port, int *addrlen)
{
	struct sockaddr_storage *raddr = (struct sockaddr_storage *)xmalloc(sizeof(struct sockaddr_storage));
	struct addrinfo hints, *res;
	int status;
	memset(&hints, 0, sizeof(hints));
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;
	if ((status = getaddrinfo(addr, NULL, &hints, &res)) != 0)
	{
		printf("getaddrinfo: %s\n", gai_strerror(status));
		return NULL;
	}

	switch (res->ai_family) {
		case (AF_INET): {
				struct sockaddr_in *s = (struct sockaddr_in*)res->ai_addr;
				s->sin_port = htons(port);
			}
			break;
		case (AF_INET6): {
				struct sockaddr_in6 *s = (struct sockaddr_in6*)res->ai_addr;
				s->sin6_port = htons(port);
			}
			break;
	}

	memcpy(raddr, res->ai_addr, res->ai_addrlen);
	*addrlen = res->ai_addrlen;
	freeaddrinfo(res);

	return raddr;
}

int create_socket(struct host_port_t *hport) {
	int addrlen = 0;
	struct sockaddr_storage *serv_addr = to_sockaddr(hport->host, hport->port, &addrlen);
	if (serv_addr == NULL) {
		printf("Got null from to_sockaddr.\n");
		return -1;
	}

	int sockfd = socket(serv_addr->ss_family, SOCK_STREAM, 0);
	if (sockfd < 0) {
		printf("Failed to get socket.\n");
		return sockfd;
	}

	int n = connect(sockfd, (struct sockaddr *) serv_addr, addrlen);
	if (n < 0) {
		printf("Failed to connect.\n");
		return n;
	}

	free(serv_addr);

	return sockfd;
}

char *to_pres(struct sockaddr_storage *in) {
	switch (in->ss_family) {
		case AF_INET: {
				char *buffer = xmalloc(sizeof(char)*INET_ADDRSTRLEN);
				const char* result=inet_ntop(AF_INET,&(((struct sockaddr_in *)in)->sin_addr),buffer,sizeof(char)*INET_ADDRSTRLEN);
				if (result==0) {
					printf("failed to convert address to string (errno=%d)",errno);
					free(buffer);
					return "127.0.0.1";
				}
				return buffer;
			}
			break;
		case AF_INET6: {
				char *buffer = xmalloc(sizeof(char)*INET6_ADDRSTRLEN);
				const char* result=inet_ntop(AF_INET6,&(((struct sockaddr_in6 *)in)->sin6_addr),buffer,sizeof(char)*INET6_ADDRSTRLEN);
				if (result==0) {
					printf("failed to convert address to string (errno=%d)",errno);
					free(buffer);
					return "::1";
				}
				return buffer;
			}
			break;
	}
}

#define BUFSIZE 512

//I got this from the internet because sockets infuriate me.
int read_line(int fd, void *buffer, size_t n)
{
    int numRead;                    /* # of bytes fetched by last read() */
    int totRead;                     /* Total bytes read so far */
    char *buf;
    char ch;

    if (n <= 0 || buffer == NULL) {
        errno = EINVAL;
        return -1;
    }

    buf = buffer;                       /* No pointer arithmetic on "void *" */

    totRead = 0;
    for (;;) {
        numRead = read(fd, &ch, 1);

        if (numRead == -1) {
            if (errno == EINTR)         /* Interrupted --> restart read() */
                continue;
            else
                return -1;              /* Some other error */

        } else if (numRead == 0) {      /* EOF */
            if (totRead == 0)           /* No bytes read; return 0 */
                return 0;
            else                        /* Some bytes read; add '\0' */
                break;

        } else {                        /* 'numRead' must be 1 if we get here */
            if (totRead < n - 1) {      /* Discard > (n - 1) bytes */
                totRead++;
                *buf++ = ch;
            }

            if (ch == '\n')
                break;
        }
    }

    *buf = '\0';
    return totRead;
}

u_char *do_request(const struct user_cap *user, in_port_t lport, in_port_t rport, struct sockaddr_storage *laddr, struct sockaddr_storage *raddr) {
	int i;
	for (i = 0; i < user->num_requests; i++) {
		char *buffer = xmalloc(BUFSIZE*sizeof(char));
		struct host_port_t *connection_data = parse_host(user->request_data[i]);
		int sockfd = create_socket(connection_data);
		if (sockfd < 0) {
			printf("socket error: %d - %s\n", sockfd, strerror(errno));
			goto next;
		}
		bzero(buffer, BUFSIZE);
		sprintf(buffer, "IDENTREQUEST %s %d %s %d\n", to_pres(laddr), lport, to_pres(raddr), rport);
		int n = send(sockfd, buffer, strlen(buffer)+1, 0);
		if (n < 0) {
			printf("send error: %d - %s\n", n, strerror(n));
			goto next;
		}

		int sorry = 32;
		while (sorry > 0) {
			sorry--;
			bzero(buffer, BUFSIZE);
			int n = read_line(sockfd, buffer, BUFSIZE-1);
			if (n < 0) {
				printf("read error: %d - %s\n", n, strerror(errno));
				goto next;
			}

			if (!((strlen(buffer) > strlen("IDENT")) && (strncmp(buffer, "IDENT", strlen("IDENT")) == 0)))
				continue;

			if ((strlen(buffer) >= (strlen("IDENTREPLY")+2)) && (strncmp(buffer, "IDENTREPLY", strlen("IDENTREPLY")) == 0)) {
				//got a reply
				u_char *reply = xmalloc(BUFSIZE*sizeof(u_char));
				sscanf(buffer, "IDENTREPLY %s\n", reply);

				if (sockfd >= 0)
					close(sockfd);
				free(buffer);
				host_free(connection_data);
				return reply;
			}

			if ((strlen(buffer) >= strlen("IDENTFAIL")) && (strncmp(buffer, "IDENTFAIL", strlen("IDENTFAIL")) == 0)) {
				goto next;
			}
		}
next:
		if (sockfd >= 0)
			close(sockfd);
		free(buffer);
		host_free(connection_data);
	}

	return strdup("IdentFailure");
}


