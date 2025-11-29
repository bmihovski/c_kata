#ifndef QUEUE_H
#define QUEUE_H

#include <stddef.h>

/* Opaque pointer to Queue structure */
typedef struct Queue Queue;

/* Create a new queue */
Queue* queue_create(void);

/* Destroy queue and free all memory */
void queue_destroy(Queue *q);

/* Add element to the end of queue */
void queue_enqueue(Queue *q, int value);

/* Remove and return element from front of queue */
int queue_dequeue(Queue *q);

/* Return element at front without removing */
int queue_peek(Queue *q);

/* Get the number of elements in queue */
size_t queue_length(Queue *q);

/* Check if queue is empty */
int queue_is_empty(Queue *q);

#endif // QUEUE_H
