
#include <unistd.h>
#include <stdio.h>

#define VALID_CHAR_START 33
#define VALID_CHAR_END 126
#define NUM_VALID_CHARS VALID_CHAR_END - VALID_CHAR_START + 1
/* +1 for inclusive char range */
#define OTHER_CHAR NUM_VALID_CHARS
#define NUM_CHARS NUM_VALID_CHARS + 1  /* valid chars +1 other/invalid chars */

struct char_count {
	char c;
	int n;
};

void init_chars(struct char_count *cs) {
	for (int c = VALID_CHAR_START; c <= VALID_CHAR_END; c++) {
		cs[c - VALID_CHAR_START].c = (char) c;
	}
}

int main(int argc, char *argv[]) {

	char c;
	struct char_count cs[NUM_CHARS] = { 0 };
	/* +1 for other characters */

	init_chars(cs);

	/* count all the characters */
	while (read(STDIN_FILENO, &c, sizeof(c))) {
		int i;

		if (c >= VALID_CHAR_START && c <= VALID_CHAR_END)
			i = ((int) c) - VALID_CHAR_START;
		else
			i = OTHER_CHAR;  /* other */
		cs[i].n++;
	}

	/* display the results */
	for (int i = 0; i < NUM_VALID_CHARS; i++) {
		char c = cs[i].c;
		int n = cs[i].n;
		printf("%c %d\n", c, n);
	}
	printf("(other) %d\n", cs[OTHER_CHAR].n);

	return 0;
}
