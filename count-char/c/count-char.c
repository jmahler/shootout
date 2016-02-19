
#include <unistd.h>
#include <stdio.h>

#define VALID_CHAR_START 33
#define VALID_CHAR_END 126
#define NUM_VALID_CHARS VALID_CHAR_END - VALID_CHAR_START + 1
/* +1 for inclusive char range */
#define OTHER_CHAR_IDX NUM_VALID_CHARS
#define OTHER_CHAR 0
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

/* insertion sort, descending */
void sort(struct char_count *a, int N) {
	for (int i = 1; i < N; i++) {
		struct char_count key = a[i];
		int j;
		for (j = i; j > 0 && key.n > a[j - 1].n; j--) {
			a[j] = a[j - 1];  /* right shift */
		}
		a[j] = key;
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
			i = OTHER_CHAR_IDX;
		cs[i].n++;
	}

	sort(cs, NUM_CHARS);

	/* display the first 10 results */
	for (int i = 0; i < 10; i++) {
		char c = cs[i].c;
		int n = cs[i].n;
		if (c == OTHER_CHAR) {
			printf("(other) %d\n", n);
		} else {
			printf("%c %d\n", c, n);
		}
	}

	return 0;
}
