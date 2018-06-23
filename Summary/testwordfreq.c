#include <stdio.h>
#include <stdlib.h>
#include "wordfreq.h"
int main () {
	char *text = (char*)calloc(100000, sizeof(char));
	text = "test TEST' test Test test.";
	char *mostfreq = (char*)calloc(100000, sizeof(char));
	wordfreq(text, mostfreq);
	printf("\n%s\n", mostfreq);
	return 0;
}