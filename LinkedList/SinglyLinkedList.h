#ifndef SINGLYLINKEDLIST_H
#define SINGLYLINKEDLIST_H

// STRUCTS
typedef struct Node_t {   // 8 bytes
    int value;
    struct Node_t *next;        // points to the next node if not NULL
} Node_t;

typedef struct LinkedList_t {   //  8 bytes
    int count;      // number of nodes in the list
    Node_t *head;       // points to the first node
} LinkedList_t;


LinkedList_t* createLinkedList();                                       // creates an empty list

Node_t* returnIndexNode(LinkedList_t *linkedList, int index);           // return index passed node

void insertNodeAtIndex(LinkedList_t *linkedList, int value, int index);  // creates a node at passed index
void push(LinkedList_t *linkedList, int value_i);                       // creates a node and put it in front
void pop(LinkedList_t *linkedList);                                     // delete head node

int readHeadValue(LinkedList_t *linkedList);                            // prints value of the first node
int readIndexValue(LinkedList_t *LinkedList_t, int index);             // prints value of the passed index node
void printList(LinkedList_t *linkedList);                               // print linked list

void deleteNodeByIndex(LinkedList_t *linkedList, int index);            // delete node at passed index
void deleteNodesByValue(LinkedList_t *linkedList, int value);           // delete nodes wtih passed value

void deleteLinkedList(LinkedList_t *linkedList);                        // delete the list completely

#endif  // SINGLYLINKEDLIST_H
