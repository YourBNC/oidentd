#ifndef __OIDENTD_USER_REQUEST_H
#define __OIDENTD_USER_REQUEST_H

/*
** Request a reply from a server
*/

u_char *do_request(const struct user_cap *user, in_port_t lport, in_port_t rport, struct sockaddr_storage *laddr, struct sockaddr_storage *raddr);

#endif

