#ifndef FINDPATTERNRM
#define FINDPATTERNRM
#include <stdio.h>
#include <stdlib.h>
int findpatternrm(char message[], char pat[]) {
	int i;
	int value = 0;
	int lentest = 0;
	int patlen = strlen(pat);
	
	for (i = 0; message[i] != '\0'; i++) {
		if (message[i] == pat[0] && message[i+(patlen - 1)] == pat[(patlen - 1)]) {
			
			while (message[i + lentest] == pat[0 + lentest]) {
				lentest = lentest + 1;
			}
			
			if (lentest == patlen) {
				return 1;
			}
		}
		lentest = 0;
	}
	return 0;
};
#endif