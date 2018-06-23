#ifndef STRIPPUNCE
#define STRIPPUNCE
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char * strippunc(char *content) {
	int i = 0;
	int trigger = 0;
	int length = strlen(content);
	int backscale = 0;
	for (i = 0; i < length + 1; i++) {
		if (content[i] == '.' || content[i] == ',' || content[i] == '"' || content[i] == '\'' || content[i] == ':' || content[i] == ';' || content[i] == '?') {
			content[i - backscale] = content[i + 1];
			trigger = 1;
		} 
		else {
			if (trigger == 1)
			{
				content[i] = ' ';
				trigger = 0;
				++backscale;
			} else {
				content[i - backscale] = content[i];
			}	
		};
	};
	// int length2 = strlen(dest);
	// dest[length2] = '\0';
	return content;
};
#endif