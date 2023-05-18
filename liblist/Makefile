OBJS = linked_list.o

liblist.a: linked_list.o
	ar crv liblist.a $(OBJS)

linked_list.o: linked_list.c list.h
	cc -c linked_list.c

clean:
	rm liblist.a *.o
