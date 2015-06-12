
CARGS=-Wall

all: bubble_sort insertion_sort

bubble_sort.o: sort.c sort.h
	gcc $(CARGS) -DBUBBLE_SORT -c $< -o $@

insertion_sort.o: sort.c sort.h
	gcc $(CARGS) -DINSERTION_SORT -c $< -o $@

readlines.o: readlines.c readlines.h
	gcc $(CARGS) -c $< -o $@

bubble_sort: main.c bubble_sort.o readlines.o
	gcc $(CARGS) $^ -o $@

insertion_sort: main.c insertion_sort.o readlines.o
	gcc $(CARGS) $^ -o $@

clean:
	-rm -f bubble_sort insertion_sort
	-rm -f *.o
