/*
 * NAME
 *
 * backtrace
 *
 * DESCRIPTION
 *
 * Shows how to generate a backtrace in C.
 *
 *   $ gcc -rdynamic backtrace.c -o backtrace
 *   $ ./backtrace 
 *   ./backtrace(fn2+0x1f) [0x400945]
 *   ./backtrace(fn1+0xe) [0x4009d0]
 *   ./backtrace(main+0xe) [0x4009e0]
 *   /lib/x86_64-linux-gnu/libc.so.6(__libc_start_main+0xf5) [0x7f5376354b45]
 *   ./backtrace() [0x400859]
 *
 * See the manpage, backtrace(3), for more info.
 */

#include <execinfo.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_SYMBOLS 100

int fn2()
{
	int i;
	int nsyms;
	char **symbols;
	void *buffer[MAX_SYMBOLS];

	nsyms = backtrace(buffer, MAX_SYMBOLS);

	symbols = backtrace_symbols(buffer, nsyms);
	if (symbols == NULL) {
		perror("backtrace_symbols");
		exit(EXIT_FAILURE);
	}

	for (i = 0; i < nsyms; i++) {
		printf("%s\n", symbols[i]);
	}

	free(symbols);

	return 0;
}

int fn1()
{
	return fn2();
}

int main()
{

	fn1();

	return 0;
}
