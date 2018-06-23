#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ALL STRINGS ARE JUST A LIST OF CHARACTERS

// This counts the number of words, by counting the spaces between word.
int wordcount(char *word) {
	int i;
	int count = 0;

	for (i = 0; i < strlen(word); ++i) {
		if (word[i] == ' ') {
			++count;
		};
	}

	return count + 1;
};

// This counts numbers of sentences by counting periods. 
int sentcount(char *sent) {
	int j;
	int count = 0;

	for (j = 0; j < strlen(sent); ++j) {
		if (sent[j] == '.') {
			++count;
		};

	}
	return count;
};