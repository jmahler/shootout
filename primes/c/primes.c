
#include <stdio.h>

int main() {

	unsigned int max = 200;
	unsigned int num = 2;
	unsigned int count = 0;
	unsigned int i;
	unsigned char found;

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
