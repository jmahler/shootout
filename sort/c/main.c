
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#include "sort.h"
#include "readlines.h"

int main()
{
	char **lines = NULL;
	size_t num_lines = 0;
	int i;

	if (readlines(&lines, &num_lines, stdin) < 0) {
		exit(EXIT_FAILURE);
	}

	/* sort the lines */
	sort(lines, num_lines);

	/* print the sorted lines */
	for (i = 0; i < num_lines; i++) {
		printf("%s", lines[i]);
	}

	freelines(lines, num_lines);

	return 0;
}
