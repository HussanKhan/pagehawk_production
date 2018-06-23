#include <stdio.h>

int main() {
	// Arrays are fixed length, and are created with int and name[some length]
	int arr[10];
	int length = 10;
	int i;
	int number = 0;

	printf("Enter 10 Numbers\n");
	for (i = 0; i < length; ++i) {
		printf("%2d> ", i);
		scanf("%d", &arr[i]);
	};

	for (i = 0; i < length; ++i) {
		printf("%d\n", arr[i]);
	};

	return 0;
}