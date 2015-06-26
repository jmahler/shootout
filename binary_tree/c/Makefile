
CFLAGS = -g -Wall

all: tree.o search

search: main.c tree.o
	gcc $(CFLAGS) $^ -o $@

tree.o: tree.c tree.h
	gcc $(CFLAGS) -DVERBOSE -c $< -o $@

clean:
	-rm -f tree.o dfs search
