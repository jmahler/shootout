
all: bubble_sort insertion_sort

bubble_sort.o: sort.c sort.h
	gcc -Wall -DBUBBLE_SORT -c $< -o $@

insertion_sort.o: sort.c sort.h
	gcc -Wall -DINSERTION_SORT -c $< -o $@

bubble_sort: main.c bubble_sort.o
	gcc -Wall $^ -o $@

insertion_sort: main.c insertion_sort.o
	gcc -Wall $^ -o $@

clean:
	-rm -f sort
	-rm -f *.o
