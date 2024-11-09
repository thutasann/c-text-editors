#include "Server.h"
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

/** function that launches the server @internal */
void launch(struct Server *server) {

    // buffer
    char buffer[30000];

    // http response
    const char *http_response =
        "HTTP/1.1 200 OK\nGMT\n"
        "Server: Apache/2.2.14 (Win32)\n"
        "Last-Modified: Wed, 22 Jul 2024 19:15:56 GMT\n"
        "Content-Type: text/html\n"
        "Connection: Closed\n\n"
        "<html>"
        "<body>"
        "<h1>HelloWorld</h1>"
        "</body>"
        "</html>";

    // server address's length
    int address_length = sizeof(server->address);

    // new socket
    int new_socket;

    while (1) {
        printf("===== WAITING FOR CONNECTION =====\n");

        new_socket = accept(server->socket, (struct sockaddr *)&server->address, (socklen_t *)&address_length);

        // read
        read(new_socket, buffer, 30000);

        printf("buffer ===> %s\n", buffer);

        write(new_socket, http_response, strlen(http_response));

        // close(new_socket);
    }
}

/** # Web Server from Scratch # */
int main(void) {

    struct Server server = server_constructor(AF_INET, SOCK_STREAM, 0, INADDR_ANY, 80, 10, launch);

    server.launch(&server);
}