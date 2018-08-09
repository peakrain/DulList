OBJ=main.o dlist.o
main:${OBJ}
	gcc -g -o main ${OBJ} -Wall
clean:
	rm -f *.o main

