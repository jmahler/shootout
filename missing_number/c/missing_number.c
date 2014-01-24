
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

int main(int argc, char* argv[]) {
	FILE *file1 = NULL;
	FILE *file2 = NULL;
	char *line = NULL;
	size_t len = 0;
	unsigned int sum1, sum2;
	unsigned int n;
	ssize_t numc;

	// check command line arguments
	if (argc != 3) {
		fprintf(stderr, "usage: %s <file1> <file2>\n", argv[0]);
		exit(1);
	}

	// open input files

	file1 = fopen(argv[1], "r");
	if (NULL == file1) {
		perror("open file1");
		exit(EXIT_FAILURE);
	}

	file2 = fopen(argv[2], "r");
	if (NULL == file2) {
		perror("open file2");
		exit(EXIT_FAILURE);
	}

	// sum all the numbers from file1
	sum1 = 0;
	while (1) {
		numc = getline(&line, &len, file1);
		if (-1 == numc)
			break;

		// remove newline
		if (line[numc - 1] == '\n') {
			line[numc - 1] = '\0';
		}

		n = atoi(line);
		sum1 += n;
	}

	// sum all the numbers from file2
	sum2 = 0;
	while (1) {
		numc = getline(&line, &len, file2);
		if (-1 == numc)
			break;

		// remove newline
		if (line[numc - 1] == '\n') {
			line[numc - 1] = '\0';
		}

		n = atoi(line);
		sum2 += n;
	}

	// free line malloc'ed by getline
	if (NULL != line) {
		free(line);
	}

	// calculate the difference
	n = (sum2 > sum1) ? sum2 - sum1 : sum1 - sum2;

	printf("%i\n", n);

	fclose(file1);
	fclose(file2);

	return 0;
}
