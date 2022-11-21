#include<stdio.h>

#include "Stack.h"

int main()
{
    Stack_t *stack = createStack();

    push(stack, 4);
    push(stack, 3);
    // top  3 -> 4

    peek(stack);

    push(stack, 2);
    push(stack, 1);
    push(stack, 0);
    // top  0 -> 1 -> 2 -> 3 -> 4

    peek(stack);

    pop(stack);
    pop(stack);
    // top  2 -> 3 -> 4

    peek(stack);

    return 0;
}