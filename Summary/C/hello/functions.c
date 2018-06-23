#include <stdio.h>

int add(int i, int j) {
	int number;
	number = i + j;
	return number;
}

int main() {
	int total;
	total = add(5, 5);
	printf("%d\n", total);
	return 0;
}