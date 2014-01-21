/*
 * revbits.c
 *
 * Given a file of 16-bit numbers, read them in, reverse the bits,
 * and output them to another file.
 *
 *   $ ./revbits ../input.bin output.bin
 *
 * To check the results do a checksum of a known good file.
 *
 *   $ md5sum output.bin ../output.bin.ok
 *   f1b35239925edf5a0cf9a3ccd7e388b6  output.bin
 *   f1b35239925edf5a0cf9a3ccd7e388b6  ../output.bin.ok
 *
 * hexedit is a good program for manually inspecting the values.
 *
 */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <unistd.h>

uint16_t revbits(uint16_t n) {
	uint16_t nr;
	unsigned int i;
	const unsigned int bits = sizeof(uint16_t)*8;

	i = 0;
	nr = 0;
	while (1) {

		// get the lowest order bit
		nr |= (n & 1);

		if (++i >= bits)
			break;

		// shift for next loop
		nr = nr << 1;
		n  = n  >> 1;
	}

	return nr;
}

int main(int argc, char* argv[]) {

	int infd, outfd;
	uint16_t n, nr;
	ssize_t res;
	const unsigned int size = sizeof(uint16_t);

	if (argc != 3) {
		fprintf(stderr, "usage: %s <in file> <out file>\n", argv[0]);
		exit(1);
	}

	infd = open(argv[1], O_RDONLY);
	if (-1 == infd) {
		perror("open");
		exit(1);
	}

	outfd = open(argv[2], O_WRONLY | O_CREAT, S_IWUSR | S_IRUSR
											| S_IRGRP | S_IROTH);
	if (-1 == infd) {
		perror("open");
		exit(1);
	}

	while (1) {
		res = read(infd, &n, size);
		if (0 == res)
			break;
		nr = revbits(n);
		res = write(outfd, &nr, size);
	}

	return 0;
}
