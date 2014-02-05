#include <stdio.h>
#include <stdlib.h>

unsigned long fibonacci(unsigned long n) {

	unsigned long n1, n2;
	unsigned long sum;

	if (0 == n)
		return 0;
	else if (n >= 1 && n <= 2)
		return 1;

	// starting from 3rd
	// 0, 1, 1, ...

	n -= 2;

	n1 = 1;
	n2 = 1;

	while(n--) {
		sum = n1 + n2;
		n1 = n2;
		n2 = sum;
	}

	return sum;
}

int main(int argc, char* argv[]) {

	unsigned long n;

	if (2 != argc) {
		fprintf(stderr, "usage: %s <n>\n", argv[0]);
		return 1;
	}

	n = atoi(argv[1]);

	n = fibonacci(n);

	printf("%li\n", n);

	return 0;
}
