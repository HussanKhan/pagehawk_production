#ifndef UNREGSPACERM
#define UNREGSPACERM
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * unregspacerm(char *text, char *spacefree) {
	int i;
	int space = 0;
	int incr_spacefree = 0;
	for (i = 0; i < strlen(text); i++) {
		if (text[i] == ' ') {
			space = 1;
		} else {
			if (space == 1)
			{	
				 spacefree[incr_spacefree] = ' ';
				 ++incr_spacefree;
				 spacefree[incr_spacefree] = text[i];
				 ++incr_spacefree;
				 space = 0;
			} else {
				spacefree[incr_spacefree] = text[i];
				++incr_spacefree;
			}
		}
	}
	spacefree[incr_spacefree] = '\0';
	return spacefree;
};
#endif