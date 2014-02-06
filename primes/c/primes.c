
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {

	unsigned int max;
	unsigned int num;
	unsigned int count;
	unsigned int i;
	unsigned char found;

	if (3 != argc) {
		fprintf(stderr, "usage: %s <start> <n>\n", argv[0]);
		return 1;
	}
	num = atoi(argv[1]);
	max = atoi(argv[2]);

	count = 0;
	while (count < max) {
		found = 1;  // default, found=true

		for (i = 2; i < num; i++) {
			if (0 == (num % i)) {
				found = 0;
				break;
			}
		}

		if (found) {
			printf("%i\n", num);
			count++;
		}

		num++;
	}

	return 0;
}
