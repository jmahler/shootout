
all: sort

sort.o: sort.c sort.h
	gcc -Wall -DBUBBLE_SORT -c $< -o $@

sort: main.c sort.o
	gcc -Wall $^ -o $@

clean:
	-rm -f sort
	-rm -f *.o
