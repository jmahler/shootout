
#include <stdio.h>
#include <stdlib.h>
#include <sys/file.h>

int main(int argc, char* argv[]) {

	char *line;
	FILE *fd;
	ssize_t res;
	size_t n;
	int fres;

	if (2 != argc) {
		fprintf(stderr, "usage: %s <file>\n", argv[0]);
		return 1;
	}

	// open, create, truncate
	fd = fopen(argv[1], "w+");
	if (NULL == fd) {
		perror("fopen");
		return 1;
	}

	printf("acquiring lock...");
	fflush(stdout);
	fres = flock(fileno(fd), LOCK_EX);
	if (-1 == fres) {
		perror("flock");
		return 1;
	}
	printf("done\n");

	printf("Enter data: ");

	line = NULL;
	n = 0;
	res = getline(&line, &n, stdin);
	if (-1 == res) {
		perror("getline");
		return 1;
	}

	res = fwrite(line, n, 1, fd);

	free(line);

	printf("releasing lock...");
	fres = flock(fileno(fd), LOCK_UN);
	if (-1 == fres) {
		perror("flock");
		return 1;
	}
	printf("done\n");

	fclose(fd);

	return 0;
}
