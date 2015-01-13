
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#include "sort.h"

#define ALLOC_LINES_INC 200

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
	sort(lines, lines_idx);

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
