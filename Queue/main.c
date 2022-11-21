#include<stdio.h>
#include<stdlib.h>
#include<memory.h>

#include "Queue.h"

int main()
{
    printf("Hello world, this is a Q\n");

    printf("size of queue is %d\n", sizeof(Queue_t));
    printf("size of node is %d\n", sizeof(Node_t));

    Queue_t *q = createQueue();

    enqueue(q, 0);
    enqueue(q, 1);
    
    peek(q);

    enqueue(q, 2);
    enqueue(q, 3);
    enqueue(q, 4);

    display(q);

    deque(q);
    deque(q);
    deque(q);

    display(q);
    return 0;
}