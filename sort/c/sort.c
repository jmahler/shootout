
#include "sort.h"

#if BUBBLE_SORT
void sort(char **lines, size_t size)
{
	size_t i;
	char change;
	char *tmp;

	do {
		change = 0;
		for (i = 1; i < size; i++) {
			if (strcmp(lines[i - 1], lines[i]) > 0) {
				change = 1;
				tmp = lines[i];
				lines[i] = lines[i - 1];
				lines[i - 1] = tmp;
			}
		}
	} while (change);
}
#elif INSERTION_SORT
void sort(char **lines, size_t size)
{
	size_t i, j;

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
