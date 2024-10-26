#include "server.h"
#include <arpa/inet.h>
#include <node_api.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

/** Handle client */
void handle_client(int client_socket) {
    char buffer[BUFFER_SIZE];
    int read_size;

    read_size = recv(client_socket, buffer, BUFFER_SIZE - 1, 0);

    if (read_size > 0) {
        buffer[read_size] = '\0'; // Null-terminate the request
        printf("Received request:\n%s\n", buffer);

        // HTTP Response
        const char *response = "HTTP/1.1 200 OK\r\n"
                               "Content-Type: text/plain\r\n"
                               "Content-Length: 13\r\n"
                               "\r\n"
                               "Hello, world!";

        send(client_socket, response, strlen(response), 0);
    }

    close(client_socket);
}

/** Start Server */
void start_server(int port) {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_addr_len = sizeof(client_addr);

    // create server socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Set server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(port);

    // Bind socket
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    // Listen for connections
    if (listen(server_socket, 5) < 0) {
        perror("Listen failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d...\n", port);

    // Accept and handle client connections
    while (1) {
        client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &client_addr_len);
        if (client_socket >= 0) {
            handle_client(client_socket);
        }
    }

    close(server_socket);
}

/** Expose `start_server` function to Node.js */
napi_value js_start_server(napi_env env, napi_callback_info args) {
    size_t argc = 1;
    napi_value argv[1];
    napi_get_cb_info(env, args, &argc, argv, NULL, NULL);

    int32_t port;
    napi_get_value_int32(env, argv[0], &port);

    // start the server on a new thread
    start_server(port);

    return NULL;
}