#ifndef CREATESTRINGEMPTY
#define CREATESTRINGEMPTY
#include <stdio.h>
// Creates string based on indexes, and return position in memory to string
char * makestringempty(int start, int end, char *content) {
	int i;
	char word[end - (start + 1)];
	char *pword = word;
	int inc = 0;

	for (i = start; i < end + 1; i++) {
		word[inc] = content[i];
		++inc;
	}
	
	word[inc] = ' ';
	word[inc + 1] = '\0';
	
	return pword;
};
#endif