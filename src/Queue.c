#include "Queue.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct Node {
    int value;
    struct Node *next;
} Node;

struct Queue {
    Node *head;
    Node *tail;
    size_t length;
};

Queue* queue_create(void) {
    Queue *q = (Queue *)malloc(sizeof(Queue));
    if (q == NULL) {
        return NULL;
    }
    q->head = NULL;
    q->tail = NULL;
    q->length = 0;
    return q;
}

void queue_destroy(Queue *q) {
    if (q == NULL) {
        return;
    }
    
    Node *current = q->head;
    while (current != NULL) {
        Node *next = current->next;
        free(current);
        current = next;
    }
    free(q);
}

void queue_enqueue(Queue *q, int value) {
    if (q == NULL) {
        return;
    }
    
    Node *new_node = (Node *)malloc(sizeof(Node));
    if (new_node == NULL) {
        return;
    }
    
    new_node->value = value;
    new_node->next = NULL;
    
    if (q->tail == NULL) {
        // Queue is empty
        q->head = new_node;
        q->tail = new_node;
    } else {
        // Add to the end
        q->tail->next = new_node;
        q->tail = new_node;
    }
    
    q->length++;
}

int queue_dequeue(Queue *q) {
    if (q == NULL || q->head == NULL) {
        return -1; // Return -1 for undefined (equivalent to TypeScript's undefined)
    }
    
    Node *old_head = q->head;
    int value = old_head->value;
    
    q->head = old_head->next;
    if (q->head == NULL) {
        q->tail = NULL; // Queue is now empty
    }
    
    free(old_head);
    q->length--;
    
    return value;
}

int queue_peek(Queue *q) {
    if (q == NULL || q->head == NULL) {
        return -1; // Return -1 for undefined
    }
    
    return q->head->value;
}

size_t queue_length(Queue *q) {
    if (q == NULL) {
        return 0;
    }
    return q->length;
}
