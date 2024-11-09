#include <Kernel/sys/types.h>
#ifndef SERVER_H
#define SERVER_H

#include <netinet/in.h>
#include <sys/socket.h>

/** Server Struct */
struct Server {
    int domain;
    int service;
    int protocol;
    u_long interface;
    int port;
    int backlog;

    struct sockaddr_in address;

    void (*launch)(void);
};

/**
    Server Constructor
 */
struct Server server_constructor(int domain, int service, int protocol, u_long interface, int port, int backlog, void (*launch)(void));

#endif