#ifndef QUEUE_H
#define QUEUE_H

typedef struct Node_t {     // 8 bytes
    int value;
    struct Node_t *next;
} Node_t;

typedef struct Queue_t {    // 12 bytes
    int count;
    Node_t *head;           // points to head
    Node_t *tail;           // points to tail
} Queue_t;

Queue_t* createQueue();     // create a queue

void enqueue(Queue_t *q, int value);       // add a node to the end of the queue
void deque(Queue_t *q);                    // delete head node
void peek(Queue_t *q);                     // print the head node value
void display(Queue_t *q);                   // print all nodes value

#endif  // QUEUE_H