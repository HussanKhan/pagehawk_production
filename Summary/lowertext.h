#ifndef LOWERTEXT
#define LOWERTEXT
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Converts all letters in a string to lowercase and returns pointer
char * lowercase (char *text) {
	int i;

	for(i = 0; i < strlen(text); i++) {
		text[i] = tolower(text[i]);
	}
	return text;
};
#endif