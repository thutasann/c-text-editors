#ifndef SOCKET_H
#define SOCKET_H

int connect_socket(const char *host, int port);
int send_message(int sockfd, const char *message);
void close_socket(int sockfd);

#endif