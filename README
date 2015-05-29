#OIdentD

Forked for use by YourBNC (from cvs repo).
Main changes: New config option. It allows one to specify a server to connect to and request the ident data. This is key to deprecating the identfile module as this module is a major slowdown for znc startup.

##Using the new request config option
The request config option assumes the following format:
````
request <ip>:<port>
````
This option can be used in place of reply.

###What does request do?
Very simple, it will contact the server specified to resolve the ident (multiple servers supported). The protocol is fairly simple too.
On connect, oidentd will send the following string (followed by a newline):
````
IDENTREQUEST <local host> <local port> <remote host> <remote port>
````
Your server can reply with one of these two strings (both ending with a newline):
````
IDENTREPLY <ident to reply with>
IDENTFAILURE
````
Replying with IDENTFAILURE or otherwise terminating the connection will result in oidentd trying the next server, or, if no other servers are available, identifying the connection as IdentFailure.

##TODO

* Make oidentd reply with a proper ident failure instead of with a "successful" ident of IdentFailure.
* Fix bugs as they arise.
