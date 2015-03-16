
all: tree.o dfs

dfs: dfs.c tree.o
	gcc -g -Wall $^ -o $@

tree.o: tree.c tree.h
	gcc -g -Wall -c $< -o $@

clean:
	-rm -f tree.o dfs
