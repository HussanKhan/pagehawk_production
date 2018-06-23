#include <stdio.h>
#include "wordstats.h"

int main() {
	char test[] = "This is a test string. Halo is a good game.";

	char *ptest = test;

	printf("\nWord Count: %d\n", wordcount(ptest));
	printf("Sentence Count: %d\n", sentcount(ptest));
	return 0;
}