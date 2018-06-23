#ifndef FINDPAT
#define FINDPAT
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "createstring.h"

int findpattern(char message[], char pat[]) {
	int i;
	int value = 0;
	int lentest = 0;
	int patlen = strlen(pat);
	
	for (i = 0; message[i] != '\0'; i++) {
		
		if (message[i] == pat[0]) {
			
			//If last letter does not match, skip ahead by i + (patlen - 1)
			if (message[i+(patlen - 1)] == pat[(patlen - 1)]) {
				while (message[i + lentest] == pat[0 + lentest]) {
					lentest = lentest + 1;
				}
			
				if (lentest == patlen) {
					value = value + 1;
				}
			} else {
				i = i + (patlen - 1);
			}
		
		} 
		lentest = 0;
	}
	return value;
}
#endif