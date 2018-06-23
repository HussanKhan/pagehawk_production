#include "StringCompare.h"

int main () {
	char word1[] = "Hello ";
	char word2[] = "Hello  ";
	if (comparestr(word2, word1))
	{
		printf("\nTRUE\n");
	}
	return 0;
}