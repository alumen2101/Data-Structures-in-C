#include<stdio.h>
#include<stdlib.h>
#include<memory.h>

#include "Queue.h"

Queue_t* createQueue()
{
    /** front
     * pop from here .... head <- node -> node -> node -> node <- tail .... push from here
     */
    Queue_t *q = malloc(sizeof(Queue_t));
    q->count = 0;
    q->head = NULL;
    q->tail = NULL;
    return q;
}

void enqueue(Queue_t *q, int value)
{
    Node_t *node = malloc(sizeof(Node_t));
    node->value = value;

    if (q->count==0)            // if queue is empty, set tail and head to the node
    {
        q->head = node;
        q->tail = node;
        node->next = NULL;          
        q->count += 1;               
        return;
    }

    Node_t *temp = q->tail;     // create a temp node for current tail
    temp->next = node;          // set temp node's next, to the newly created node
    q->tail = node;             // set q->tail to the new node
    q->count += 1;               
    temp = NULL;

}

void deque(Queue_t *q)
{
    if (q->count == 0 )
    {
        printf("ERROR: QUEUE IS EMPTY, CANNOT DEQUE\n");
        return;
    } 

    Node_t *node = q->head;

    if (q->count == 1)
        q->head, q->tail = NULL;
    else
        q->head = node->next;

    node = NULL;
    free(node);
    q->count -= 1;
}

void display(Queue_t *q)
{
    Node_t *node = q->head;
    for (int i=0; i < q->count; i++)
    {
        printf("%d ", node->value);
        node = node->next;
    }
    printf("\n");
}