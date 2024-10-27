#include "./include/socket.h"
#include <arpa/inet.h>
#include <node_api.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/** Connect Socket */
int connect_socket(const char *host, int port) {
    int sockfd;
    struct sockaddr_in server_addr;

    // create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        perror("Socket creation Failed\n");
        return -1;
    }

    // set server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    if (inet_pton(AF_INET, host, &server_addr.sin_addr) <= 0) {
        perror("Invalid address");
        close(sockfd);
        return -1;
    }

    // connect to server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        close(sockfd);
    }

    return sockfd;
}

/** Send Message */
int send_message(int sockfd, const char *message) {
    int len = send(sockfd, message, strlen(message), 0);
    if (len < 0) {
        perror("Send failed");
    }
    return len;
}

/** Close Socket */
void close_socket(int sockfd) {
    close(sockfd);
}

/** Helper function to get integer from JS */
int get_int32(napi_env env, napi_value value) {
    int32_t result;
    napi_get_value_int32(env, value, &result);
    return result;
}

/** Helper function to get string from JS */
char *get_string(napi_env env, napi_value value) {
    size_t str_size;
    napi_get_value_string_utf8(env, value, NULL, 0, &str_size);
    char *str = (char *)malloc(sizeof(str_size + 1));
    napi_get_value_string_utf8(env, value, str, str_size + 1, &str_size);
    return str;
}

/** Expose `connect_socket` to JS */
napi_value js_connect_socket(napi_env env, napi_callback_info args) {
    size_t argc = 2;
    napi_value argv[2];
    napi_get_cb_info(env, args, &argc, argv, NULL, NULL);

    char *host = get_string(env, argv[0]);
    int port = get_int32(env, argv[1]);

    int sockfd = connect_socket(host, port);
    free(host);

    napi_value result;
    napi_create_int32(env, sockfd, &result);

    return result;
}

/** Expose `send_message` to JS */
napi_value js_send_message(napi_env env, napi_callback_info args) {
    size_t argc = 2;
    napi_value argv[2];
    napi_get_cb_info(env, args, &argc, argv, NULL, NULL);

    int sockfd = get_int32(env, argv[0]);
    char *message = get_string(env, argv[1]);

    int len = send_message(sockfd, message);
    free(message);

    napi_value result;
    napi_create_int32(env, len, &result);
    return result;
}

/** Expose `close_socket` to JS */
napi_value js_close_socket(napi_env env, napi_callback_info args) {
    size_t argc = 1;
    napi_value argv[1];
    napi_get_cb_info(env, args, &argc, argv, NULL, NULL);

    int sockfd = get_int32(env, argv[0]);
    close_socket(sockfd);

    return NULL;
}
