output: main.o SinglyLinkedList.o
	gcc main.o SinglyLinkedList.o -o output

main.o: main.c
	gcc -c main.c

SinglyLinkedList.o: SinglyLinkedList.c SinglyLinkedList.h
	gcc -c SinglyLinkedList.c

clean:
	del *.o output.*