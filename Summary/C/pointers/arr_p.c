#include <stdio.h>
#include <string.h>
// POINTERS ARE AWESOME FOR GOING THROUGH ARRAYS
int main (void) {
	int i;
	char word[] = "Hello World!";
	char *pword = word;

	// for (i = 0; i < strlen(word); ++i) {
	// 	printf("word[%d] = %c *(pword+%d) = %c &word[%d] = %p pword+%d = %p\n", i, word[i], i, *(pword+i), i, &word[i], i, pword+i);
	// }
	char *lastadd = pword;
	for (i = 0; i < strlen(pword); ++i) {
		printf("%c", pword[i]);
		printf("\n");
	};

	while (*lastadd) {
		printf("Address: %p\n", lastadd);
		++lastadd;

	}

	printf("%d", (int)(lastadd-pword));
	
	return 0;
}