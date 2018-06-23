#ifndef COPYPASTESTRING
#define COPYPASTESTRING
#include <stdio.h>
#include <string.h>

//Copy and pastes strings
char transferstring(char *src, char *dest, int index) {
	int i;
	int inc = 0;
	int endingspace = (index + (strlen(src)) + 1);
	for (i = index; i < endingspace; i++) {
		dest[i] = src[inc];
		++inc;
	}
	// dest[inc] = '\0';
	return 0;
};
#endif