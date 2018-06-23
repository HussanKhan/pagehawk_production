#ifndef RMSTOPWORDS
#define RMSTOPWORDS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "createstring.h"
#include "copypastestring.h"
#include "stopwordcheck.h"

int cleantext (char *text, char *cleantext) {
	int i;
	int start = 0;
	int end = 0;
	char *tempword;
	int index = 0;

	for (i = 0; text[i] != '\0'; i++) {
		if (text[i] == ' ') {
			end = i - 1;
			start = start;

			tempword = makestring(start, end, text);

			if(stopwordcheck(tempword) == 1) {
				free(tempword);
			} else {
				transferstring(tempword, cleantext, index);
				index = index + (end - start) + 1;
				free(tempword);
			}

			start = end + 1;
		} 
}
	return 0;
};
#endif

