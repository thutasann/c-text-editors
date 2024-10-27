#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stddef.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

/** Insert Node */
Node *insert_node(Node *head, int data);

/** Delete Node */
Node *delete_node(Node *head, int data);

/** Display */
void display(Node *head);

#endif