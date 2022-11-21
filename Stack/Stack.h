#ifndef STACK_H
#define STACK_H


typedef struct Node_t {
    int value;
    struct Node_t *next;
} Node_t;

typedef struct Stack_t {
    Node_t *top;        // points to top of the stack
} Stack_t;

Stack_t* createStack();     // creates Stack
void push(Stack_t *s, int value);   // push node to stack
void pop(Stack_t *s);       // delete first node
void peek(Stack_t *s);      // read first node value

#endif      // STACK_H