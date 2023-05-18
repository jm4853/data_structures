demo: demo.o
	cc -o demo -Lliblist demo.o -llist

demo.o: demo.c
	cc -c -Iliblist demo.c

clean:
	rm demo *.o
