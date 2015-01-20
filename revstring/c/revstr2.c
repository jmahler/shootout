#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char* revstr(const char *str)
{
	int len, end;
	int i;
	char *new_str;

	len = strlen(str);
	new_str = malloc(len + 1);  /* + null */
	if (new_str == NULL) {
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	new_str[len] = '\0';
	end = len - 1;

	for (i = 0; i < len; i++) {
		new_str[i] = str[end - i];
	}

	return new_str;
}

int main(int argc, char *argv[])
{
	char *str;

	if (argc != 2) {
		fprintf(stderr, "usage: %s <str>\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	str = argv[1];

	str = revstr(str);

	printf("%s\n", str);

	free(str);

	return 0;
}
