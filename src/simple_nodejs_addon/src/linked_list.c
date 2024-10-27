#include "./include/linked_list.h"
#include <node_api.h>
#include <stdio.h>
#include <stdlib.h>

Node *insert_node(Node *head, int data) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = head;
    return new_node;
}

Node *delete_node(Node *head, int data) {
    Node *temp = head, *prev = NULL;
    while (temp != NULL && temp->data != data) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
        return head;

    if (prev == NULL)
        head = temp->next;
    else
        prev->next = temp->next;

    free(temp);

    return head;
}

void display(Node *head) {
    Node *current = head;
    while (current != NULL) {
        printf("%d ->", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// --------- Expose Functions to Javascript
Node *head_link = NULL;

/** Expose Insert */
napi_value Insert(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    int32_t data;
    napi_get_value_int32(env, args[0], &data);

    head_link = insert_node(head_link, data);
    return NULL;
}

/** Expose Delete */
napi_value Delete(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1];
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    int32_t data;
    napi_get_value_int32(env, args[0], &data);

    head_link = delete_node(head_link, data);
    return NULL;
}

/** Expose Display */
napi_value Display(napi_env env, napi_callback_info info) {
    display(head_link);
    return NULL;
}