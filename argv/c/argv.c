
#include <stdio.h>

int main(int argc, char *argv[])
{
	int i;

	printf("%d arguments\n", argc);

	for (i = 0; i < argc; i++) {
		printf("%d: '%s'\n", i, argv[i]);
	}

	return 0;
}
