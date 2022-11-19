#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <time.h>

#include "SinglyLinkedList.h"

void calculateTime(){
    clock_t start, end;
    double cpu_time_used;

    start = clock();

    LinkedList_t *numbers = createLinkedList();     
    // TODO FREE()

    // pushing N nodes to the list
    for (int i=0; i<1000000; i++)
    {
        push(numbers, i);
    }

    free(numbers);

    end = clock();

    cpu_time_used = ((double) (end-start)) / CLOCKS_PER_SEC;
    printf("took %f seconds to execute\n", cpu_time_used);

}

int main()
{
    // TODO FREE()
    LinkedList_t *numbers = createLinkedList();     

    push(numbers, 0);
    push(numbers, 1);
    push(numbers, 2);
    push(numbers, 3);

    printf("linked list values are: ");
    printList(numbers);

    printf("--------\n");

    insertNodeAtIndex(numbers, 5, 2);
    insertNodeAtIndex(numbers, 9, 0);
    insertNodeAtIndex(numbers, 12, 4);

    printf("linked list values after insertions are: ");
    printList(numbers);

    printf("--------\n");

    pop(numbers);
    pop(numbers);

    printf("linked list values after 2 pop() are: ");
    printList(numbers);

    printf("--------\n");

    printf("the value of head is: %d\n",readHeadValue(numbers));
    printf("the value of node at index 1 is: %d\n", readIndexValue(numbers, 1));
    printList(numbers);

    printf("--------\n");

    insertNodeAtIndex(numbers, 3, 2);
    insertNodeAtIndex(numbers, 3, 4);

    printf("linked list values after insertions are: ");
    printList(numbers);

    printf("--------\n");

    deleteNodesByValue(numbers, 3);
    printf("linked list values after deleting every node with value of 3 are: ");
    printList(numbers);

    printf("--------\n");

    deleteLinkedList(numbers);
    
    free(numbers);
    return 0;
}

