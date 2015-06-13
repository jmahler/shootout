
#include "sort.h"

#if BUBBLE_SORT
void sort(char **lines, int size)
{
	int i;
	char *tmp;
	int no_change;

	while (1) {
		no_change = 1;
		for (i = 1; i < size; i++) {
			if (strcmp(lines[i - 1], lines[i]) > 0) {
				no_change = 0;

				tmp = lines[i];
				lines[i] = lines[i - 1];
				lines[i - 1] = tmp;
			}
		}
		if (no_change)
			break;
	}
}
#elif INSERTION_SORT
void sort(char **lines, int size)
{
	unsigned int i, j;

	for (i = 1; i < size; i++) {
		char *key = lines[i];

		for (j = i; j > 0 && strcmp(lines[j - 1], key) > 0; j--) {
			lines[j] = lines[j - 1];
		}
		lines[j] = key;
	}
}
#else
#error "One of the sorting algorithms must be chosen."
#endif
