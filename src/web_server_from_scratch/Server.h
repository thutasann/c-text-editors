#include <Kernel/sys/types.h>
#ifndef SERVER_H
#define SERVER_H

#include <netinet/in.h>
#include <sys/socket.h>

/**
 * Server structure representing server configuration and setup details.
 */
struct Server {
    int domain;       /**< Protocol family (e.g., AF_INET for IPv4). */
    int service;      /**< Type of service (e.g., SOCK_STREAM for TCP). */
    int protocol;     /**< Protocol to be used (e.g., IPPROTO_TCP for TCP). */
    u_long interface; /**< IP address to bind to, typically INADDR_ANY. */
    int port;         /**< Port number on which the server listens. */
    int backlog;      /**< Maximum length for the queue of pending connections. */

    struct sockaddr_in address; /**< Socket address structure for the server. */

    void (*launch)(void); /**< Pointer to the function that launches the server. */
};

/**
 * Constructs a server with specified parameters.
 *
 * @param domain    The protocol family (e.g., AF_INET for IPv4).
 * @param service   The type of service (e.g., SOCK_STREAM for TCP).
 * @param protocol  The protocol to be used (e.g., IPPROTO_TCP for TCP).
 * @param interface The IP address to bind to, typically `INADDR_ANY`.
 * @param port      The port number on which the server listens.
 * @param backlog   The maximum length for the queue of pending connections.
 * @param launch    A function pointer to the server's launch routine.
 *
 * @return A Server struct initialized with the provided parameters.
 */
struct Server server_constructor(int domain, int service, int protocol, u_long interface, int port, int backlog, void (*launch)(void));

#endif