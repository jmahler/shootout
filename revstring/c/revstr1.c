#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void revstr(char *str)
{
	int end, mid;
	int i;
	char tmp;

	end = strlen(str);	/* first, use end as length */
	mid = end / 2;		/* mid value to be swapped */
	end = end - 1;		/* offset to end value */

	for (i = 0; i < mid; i++) {
		tmp = str[i];
		str[i] = str[end - i];
		str[end - i] = tmp;
	}
}

int main(int argc, char *argv[])
{
	char *str;

	if (argc != 2) {
		fprintf(stderr, "usage: %s <str>\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	str = argv[1];

	revstr(str);

	printf("%s\n", str);

	return 0;
}
