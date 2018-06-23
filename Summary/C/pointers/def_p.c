#include <stdio.h>

int main() {
	long long int num = 532328482387;
	long long int *number = &num;
	// * means to get value the pointer points to
	printf("\nPointer Final Value: %lld\n", *number);
	// This prints memory address address
	// Or pointers value, which ic address
	printf("(What it holds)Pointer Value Address: %p\n", number);
	printf("Num Address: %p\n", &num);

	// This is the address of the pointer itself
	printf("Pointers Own Address: %p\n", &number);

	// See the points size
	printf("Pointers Size: %d bytes\n", (int)sizeof(number));
	printf("num variable Size: %d bytes\n", (int)sizeof(num));

	return 0;
}