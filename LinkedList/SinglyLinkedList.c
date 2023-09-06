#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "SinglyLinkedList.h"

// initialize linked list
LinkedList_t *createLinkedList()
{
    size_t len = sizeof(LinkedList_t);
    LinkedList_t *linkedLList = malloc(len); // create list and allocate memory

    memset(linkedLList, 0, len);

    linkedLList->count = 0;   // set count to 0
    linkedLList->head = NULL; // set head to null

    return linkedLList;
}

// check if index is in bound. if true return index
// can accept reverse index --> -1 is the last index
int checkIndexInBound(int count, int index)
{
    if (index <= count - 1 && index >= count * -1)
    {
        if (index < 0)
        {
            return count + index;
        }
        else
        {
            return index;
        }
    }
    else
    {
        printf("ERROR: INDEX OUT OF BOUNDS\n");
        exit(EXIT_FAILURE);
    }
}

// returns node at the index passed
Node_t *returnIndexNode(LinkedList_t *linkedList, int index)
{
    index = checkIndexInBound(linkedList->count, index);
    Node_t *node = linkedList->head;
    for (int i = 0; i < index; i++)
    {
        node = node->next;
    }
    return node;
}

// insert node in at index 0
void push(LinkedList_t *linkedList, int value_i)
{
    size_t len = sizeof(Node_t);
    Node_t *node = malloc(len); // allocate Node_t size for new node

    memset(node, 0, len);

    linkedList->count += 1; // increase count of the linkedlist

    node->next = linkedList->head; // new node head points to linkedlist head(whihch is now 2nd node)
    node->value = value_i;         // assign new node value
    linkedList->head = node;       // linkedlist head point to new node
}

// return linkedList head
int readHeadValue(LinkedList_t *linkedList)
{
    if (linkedList->count == 0)
    {
        printf("ERROR: Passed Linked-List is empty.\n");
        exit(EXIT_FAILURE);
    }
    return linkedList->head->value;
}

// return node's value at passed index
int readIndexValue(LinkedList_t *linkedList, int index)
{
    index = checkIndexInBound(linkedList->count, index);
    Node_t *node = linkedList->head; // get list head address
    for (int i = 0; i < index; i++)
    {
        node = node->next; // get the passed index node
    }

    int value = node->value;
    node = NULL;
    return value;
}

// print linked list nodes value
void printList(LinkedList_t *linkedList)
{
    Node_t *next = linkedList->head;
    while (next != NULL) // traverse through list till it hits node.next==NULL
    {
        printf("%d ", next->value);
        next = next->next;
    }
    printf("\n");
}

// delete head node
void pop(LinkedList_t *linkedList)
{
    Node_t *temp = linkedList->head; // save list head in a temporarily pointer
    linkedList->head = linkedList->head->next; // set list head to the next node of head
    linkedList->count -= 1; // decrease count of list
    free(temp);             // free allocated memory
    temp = NULL;            // set pointer to NULL
}

// insert a node at passed index
int insertNodeAtIndex(LinkedList_t *linkedList, int value, int index)
{
    index = checkIndexInBound(linkedList->count, index);

    size_t len = sizeof(Node_t);
    Node_t *node = malloc(len); // create node and allocate memory
    node->value = value;                   // set node value

    if (index == 0)
    {
        push(linkedList, value);
    }
    else
    {
        Node_t *prevNode = returnIndexNode(linkedList, index - 1); // node behind index
        node->next = prevNode->next;
        prevNode->next = node;

        prevNode = NULL;
        linkedList->count += 1;
    }
    node = NULL;

}

// deletes node at passed index
void deleteNodeByIndex(LinkedList_t *linkedList, int index)
{
    index = checkIndexInBound(linkedList->count, index);    // check index is ok
    if (index == 0) 
    {
        pop(linkedList);    // if index is zero, just pop()
    }
    else
    {
        Node_t *prevNode = returnIndexNode(linkedList, index - 1);  // get previous node of the passed index
        Node_t *node = prevNode->next;

        prevNode->next = node->next;
        node->next = NULL;
        free(node);
        node = NULL;
        prevNode = NULL;
        linkedList->count -= 1;
    }
}

//deletes node with passed value
void deleteNodesByValue(LinkedList_t *linkedList, int value)
{
    Node_t *node = linkedList->head;
    for (int i = 0; i < linkedList->count; i++)
    {
        if (node->value == value)
        {
            node = node->next;      // get the next node because if delete is first, we will lose the rest of the list
            deleteNodeByIndex(linkedList, i);
            i -= 1;     // so that loop doest jump a over next node
            /**
             * if node at index 2 is deleted, before deletion the next node
             * was at index 3, but after deletion it is at index 2
             * so we have to decrease counter so to check the node after
             * the deleted node
             */
        }
        else
        {
            node = node->next;
        }
    }
    node = NULL;
}

// delete the list -- will free the memory as well
void deleteLinkedList(LinkedList_t *linkedList)
{
    int count = linkedList->count;
    for (int i=count-1; i<0; i++)     // start from tail to head
    {
        deleteNodeByIndex(linkedList, i);
    }
    printf("Linked List deallocated from memory completely\n");
}
