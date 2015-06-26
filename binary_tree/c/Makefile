
CFLAGS = -Wall

all: search

search: main.c tree.o queue.o
	gcc $(CFLAGS) $^ -o $@

tree.o: tree.c tree.h
	gcc $(CFLAGS) -DVERBOSE -c $< -o $@

queue.o: queue.c queue.h
	gcc $(CFLAGS) -c $< -o $@

clean:
	-rm -f *.o
	-rm -f search
