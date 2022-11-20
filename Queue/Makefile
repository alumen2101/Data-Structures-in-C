output: main.o Queue.o
	gcc main.o Queue.o -o output

main.o: main.c
	gcc -c main.c

Queue.o: Queue.c
	gcc -c Queue.c

clean:
	del *.o output.*