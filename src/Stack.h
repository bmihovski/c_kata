#ifndef SRC_STACK_H_
#define SRC_STACK_H_

#include <stddef.h>
typedef struct Stack Stack;

Stack *createStack(void);
void destroyStack(Stack *stack);
int pop(Stack *stack);
int peek(Stack *stack);
size_t length(Stack *stack);
void push(Stack *stack, int value);

#endif // SRC_STACK_H_
