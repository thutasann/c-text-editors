#include "Server.h"
#include <stdio.h>
#include <stdlib.h>

struct Server server_constructor(int domain, int service, int protocol, u_long interface, int port, int backlog, void (*launch)(struct Server *server)) {
    struct Server server;

    // construct the server
    server.domain = domain;
    server.service = service;
    server.protocol = protocol;
    server.interface = interface;
    server.port = port;
    server.backlog = backlog;

    // address
    server.address.sin_family = domain;
    server.address.sin_port = htons(port);
    server.address.sin_addr.s_addr = htonl(interface);

    // socket connection to allow operating system to community with the network
    server.socket = socket(domain, service, protocol);
    if (server.socket == 0) {
        perror("Failed to connect socket...\n");
        exit(1);
    }

    // bind the socket to the network
    if ((bind(server.socket, (struct sockaddr *)&server.address, sizeof(server.address))) < 0) {
        perror("Falied to bind socket...\n");
        exit(1);
    }

    // listen server
    if ((listen(server.socket, server.backlog)) < 0) {
        perror("Failed to start listening...\n");
        exit(1);
    }

    // launch function
    server.launch = launch;

    return server;
}