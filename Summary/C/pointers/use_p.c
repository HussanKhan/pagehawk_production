#include <stdio.h>

int main() {
	char name[] = "Hello World!";
	char *pname = name;

	printf("%s\n", pname);
	printf("Address of name: %p\n", name);
	printf("Value of pname: %p\n", pname);
	printf("Address of pname Pointer: %p\n", &pname);

	printf("\nChange Name Value: \n");
	scanf("%s", pname);
	printf("Changed to: %s\n", name);
	printf("Address of name: %p\n", name);
	printf("Value of pname: %p\n", pname);

	// Using scanf with points
	int value = 0;
	int *pvalue = &value;

	printf("Enter Any Number: ");
	// POinter can change value of original value
	// We assigned to pvalue, but value also changed
	scanf("%d", pvalue);
	printf("\nYou Entered: %d\n", value);
	return 0;
}