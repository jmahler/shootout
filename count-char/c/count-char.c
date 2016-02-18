
#include <unistd.h>
#include <stdio.h>

#define VALID_CHAR_START 33
#define VALID_CHAR_END 126
#define NUM_VALID_CHARS VALID_CHAR_END - VALID_CHAR_START + 1
/* +1 for inclusive char range */
#define OTHER_CHAR NUM_VALID_CHARS
/* count of other chars is at the end */

int main(int argc, char *argv[]) {

	char c;
	int cs[NUM_VALID_CHARS + 1] = { 0 };
	/* +1 for other characters */

	/* count all the characters */
	while (read(STDIN_FILENO, &c, sizeof(c))) {
		int i;

		if (c >= VALID_CHAR_START && c <= VALID_CHAR_END)
			i = ((int) c) - VALID_CHAR_START;
		else
			i = OTHER_CHAR;  /* other */
		cs[i]++;
	}

	/* display the results */
	for (int i = 0; i < NUM_VALID_CHARS; i++) {
		char c = i + VALID_CHAR_START;
		printf("%c %d\n", c, cs[i]);
	}
	printf("(other) %d\n", cs[OTHER_CHAR]);

	return 0;
}
