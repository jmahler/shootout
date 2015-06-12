
#include "readlines.h"

int freelines(char **lines, size_t n)
{
	int i;

	for (i = 0; i < n; i++) {
		free(lines[i]);
	}
	free(lines);

	return 0;
}

int readlines(char ***lines, size_t *n, FILE *stream)
{
	size_t lines_idx = 0;
	size_t lines_alloc = 0;
	char *line;
	ssize_t ret;

	for(;;) {
		size_t line_n;

		if (lines_idx >= lines_alloc) {
			lines_alloc = lines_alloc ? lines_alloc * 2 : 10;

			*lines = realloc(*lines, lines_alloc * sizeof(lines));
			if (!(*lines)) {
				perror("realloc");
				goto err;
			}
		}

		line_n = 0;
		line = NULL;
		ret = getline(&line, &line_n, stream);
		if (ret == -1) {
			if (errno == 0)
				break;

			perror("getline");
			free(line);
			goto err;
		}
		(*lines)[lines_idx++] = line;
		(*n)++;
	}

	/* We might have allocated more lines than necessary,
	 * de-allocate back down to only those we used.
	 */
	*lines = realloc(*lines, (*n) * sizeof(lines));
	if (!(*lines)) {
		perror("realloc");
		goto err;
	}

	return *n;

err:
	freelines(*lines, *n);

	return -1;
}
