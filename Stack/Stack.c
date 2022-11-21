#include<stdio.h>
#include<stdlib.h>
#include<memory.h>

#include "Stack.h"

Stack_t* createStack()
{
    Stack_t *s = malloc(sizeof(Stack_t));
    s->top = NULL;

    return s;
}

void push(Stack_t *s, int value)
{
    Node_t *node = malloc(sizeof(Node_t));
    node->value = value;
    node->next = s->top;
    s->top = node;
}

void pop(Stack_t *s)
{
    Node_t *node = s->top;
    s->top = node->next;

    free(node);
    node = NULL;
}

void peek(Stack_t *s)
{
    printf("value of the top node is %d\n", s->top->value);
}