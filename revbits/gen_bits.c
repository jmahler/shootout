/*
 * gen_bits.c
 *
 * Used to generate a file of 500 16-bit numbers.
 *
 *   $ ./gen_bits file.bin
 */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <inttypes.h>

#define NUM 500

int main(int argc, char *argv[]) {

	int outfd;
	uint16_t i;

	if (argc != 2) {
		fprintf(stderr, "Usage: %s <out>\n", argv[0]);
		exit(1);
	}

	outfd = open(argv[1], O_WRONLY | O_CREAT, S_IWUSR | S_IRUSR
											| S_IRGRP | S_IROTH);
	if (-1 == outfd) {
		perror("open");
		exit(1);
	}

	for (i = 0; i < NUM; i++) {
		write(outfd, &i, sizeof(i));
	}

	close(outfd);

	return 0;
}
