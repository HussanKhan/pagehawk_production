#ifndef DOUBLECOPYSTRING
#define DOUBLECOPYSTRING
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <string.h>

//This function creates two copies of a string. Copies are all lowercase
char doublecopystring(char *src, char *copy1, char *copy2) {
	int i;
	int incr = 0;
	char tempchar;
	for (i = 0; src[i] != '\0'; i++) {
		tempchar = tolower(src[i]);
		copy1[i] = tempchar;
		copy2[i] = tempchar;
		++incr;
	}
	copy1[incr + 1] = '\0';
	copy2[incr + 1] = '\0';
	return 0;
};
#endif