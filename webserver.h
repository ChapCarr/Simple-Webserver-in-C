#ifndef WEBSERVER_H
#define WEBSERVER_H

#include <sys/socket.h>
#include <netinet/in.h>

typedef struct Server
{
    struct sockaddr_in address;

    int domain;
    int protocol;
    int service;
    in_addr_t interface; // u_long did not work
    int port;
    int backlog;

    int socket;

    void (*launch)(struct Server *server);
} Server;

Server server_constructor(int domain, int service, int protocol, in_addr_t interface, int port, int backlog, void(*launch)(struct Server *server));

#endif // WEBSERVER_H