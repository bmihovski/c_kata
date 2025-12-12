#include "Stack.h"
#include <stdlib.h>

typedef struct Node {
  int value;
  struct Node *prev;
} Node;

struct Stack {
  Node *head;
  size_t length;
};

Stack *createStack(void) {
  Stack *newStack = (Stack *)malloc(sizeof(Stack));
  newStack->head = NULL;
  newStack->length = 0;
  return newStack;
}
void destroyStack(Stack *stack) {
  if (NULL == stack) {
    return;
  }
  Node *currentNode = stack->head;
  while (currentNode) {
    Node *temp = currentNode->prev;
    free(currentNode);
    currentNode = temp;
  }
  free(stack);
}
void push(Stack *stack, int value) {
  if (NULL == stack) {
    return;
  }
  stack->length++;
  auto *newNode = (Node *)malloc(sizeof(Node));
  newNode->value = value;
  if (1 == length(stack)) {
    stack->head = newNode;
  } else {
    newNode->prev = stack->head;
    stack->head = newNode;
  }
}
int pop(Stack *stack) {
  int returnValue = -1;
  if (NULL == stack || !stack->length) {
    return returnValue;
  }
  auto *currentHead = stack->head;
  returnValue = stack->head->value;
  stack->length--;
  if (0 < stack->length) {
    stack->head = currentHead->prev;
  }
  free(currentHead);
  return returnValue;
}
int peek(Stack *stack) {
  if (NULL == stack || !stack->length) {
    return -1;
  }
  return stack->head->value;
}
size_t length(Stack *stack) { return stack->length; }
