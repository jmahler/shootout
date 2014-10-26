/*
 * NAME
 *
 * getopt - show how to get argv options
 *
 * DESCRIPTION
 *
 * This program shows how to take either a flag option or a key/value
 * pair.  The value of the arguments are printed as the result.
 *
 *   $ getopt -f -k abc
 *   flag = 1
 *   key = 'abc'
 *
 *   $ getopt -k abc
 *   flag = 0
 *   key = 'abc'
 * 
 * AUTHOR
 *
 * Jeremiah Mahler <jmmahler@gmail.com>
 * http://github.com/jmahler
 *
 * COPYRIGHT
 *
 * Copyright (c) 2014, Jeremiah Mahler. All Rights Reserved.
 * This project is free software and released under the
 * GNU General Public License.
 */

#include <stdio.h>
#include <unistd.h>

void usage(char *proc) {
	fprintf(stderr, "usage: %s [-f] [-k key]\n", proc);
}

int main(int argc, char *argv[])
{
	int opt;
	int flag = 0;
	char *key = "";

	while ((opt = getopt(argc, argv, "fk:")) != -1) {
		switch (opt) {
		case 'f':
			flag = 1;
			break;
		case 'k':
			key = optarg;
			break;
		default:
			usage(argv[0]);
			return 1;  /* error */
		}
	}

	printf("flag = %i\n", flag);
	printf(" key = '%s'\n", key);

	return 0;
}
