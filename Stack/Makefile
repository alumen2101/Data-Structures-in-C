output: main.o Stack.o
	gcc main.o Stack.o -o output

main.o: main.c
	gcc -c main.c

Stack.o: Stack.c Stack.h
	gcc -c Stack.c

clean:
	del *.o output.*