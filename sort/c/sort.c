
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define ALLOC_LINES_INC 200

static void bubble_sort(char **lines, int size)
{
	int i;
	char *tmp;
	int no_change;

	while (1) {
		no_change = 1;
		for (i = 1; i < size; i++) {
			if (strcmp(lines[i - 1], lines[i]) > 0) {
				no_change = 0;

				tmp = lines[i];
				lines[i] = lines[i - 1];
				lines[i - 1] = tmp;
			}
		}
		if (no_change)
			break;
	}
}

int main()
{
	char **lines = NULL;
	int lines_idx = 0;
	size_t lines_alloc = 0;
	char *line;
	ssize_t ret;
	size_t n;
	int i;

	/* read in all the lines */
	while(1) {
		/* alloc space for line pointers if needed */
		if (lines_idx >= lines_alloc) {
			lines_alloc += ALLOC_LINES_INC;
			lines = realloc(lines, lines_alloc * sizeof(lines));
			if (!lines) {
				perror("realloc");
				exit(EXIT_FAILURE);
			}
		}

		n = 0;
		line = NULL;
		ret = getline(&line, &n, stdin);
		if (ret < 0)
			break;
		lines[lines_idx++] = line;
	}

	/* sort the lines */
	bubble_sort(lines, lines_idx);

	/* print the sorted lines */
	for (i = 0; i < lines_idx; i++) {
		printf("%s", lines[i]);
	}

	/* free the memory */
	for (i = 0; i < lines_idx; i++) {
		free(lines[lines_idx]);
	}
	free(lines);

	return 0;
}
