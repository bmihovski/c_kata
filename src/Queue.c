#include "Queue.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int value;
  struct Node *next;
} Node;

struct Queue {
  Node *head;
  Node *tail;
  size_t length;
};

Queue *queue_create(void) {
  Queue *queue = (Queue *)malloc(sizeof(Queue));
  queue->head = NULL;
  queue->tail = NULL;
  queue->length = 0;
  return queue;
}

void queue_destroy(Queue *q) {
  if (q == NULL) {
    return;
  }
  auto *currNode = q->head;
  while (currNode) {
    auto *nextNode = currNode->next;
    free(currNode);

    currNode = nextNode;
  }
  q->head = NULL;
  q->tail = NULL;
  q->length = 0;
  free(q);
}

void queue_enqueue(Queue *q, int value) {
  if (NULL == q) {
    return;
  }
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->value = value;
  newNode->next = NULL;
  if (0 == q->length) {
    q->head = newNode;
    q->tail = newNode;
    q->length++;
  } else {
    q->tail->next = newNode;
    q->tail = newNode;
    q->length++;
  }
}

int queue_dequeue(Queue *q) {
  if (NULL == q || NULL == q->tail || !queue_length(q)) {
    return -1;
  }
  if (1 == q->length) {
    int curr = q->head->value;
    q->length--;
    q->tail = NULL;
    return curr;
  }
  auto *oldHead = q->head;
  int curr = oldHead->value;
  q->head = oldHead->next;
  q->length--;
  if (NULL == q->head) {
    q->tail = NULL;
  }
  free(oldHead);
  return curr;
}

int queue_peek(Queue *q) {
  if (NULL == q || NULL == q->head) {
    return -1;
  }
  return q->head->value;
}

size_t queue_length(Queue *q) {
  if (NULL == q) {
    return 0;
  }
  return q->length;
}
int queue_is_empty(Queue *q) {
  if (NULL == q || 0 == q->length) {
    return 1;
  }
  return 0;
}
