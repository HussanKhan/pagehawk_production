#include <stdio.h>
#include <stdint.h>

int main() {
	long unsigned int i; //inner loop counter
	long unsigned int fibs[102] = {0};
	long unsigned int total;
	long unsigned int pos2;

	//Hardcoded numbers
	fibs[0] = 0;
	fibs[1] = 1;

	for (i = 0; i < 100; ++i) {
		total = fibs[i] + fibs[i+1];
		pos2 = (int)(i + 2);
		fibs[pos2] = total;
	}

	printf("Fib Numbers\n");

	for (i = 0; i< 100; ++i) {
		printf("%lu > %lu\n", i, fibs[i]);
	}
	return 0;
}