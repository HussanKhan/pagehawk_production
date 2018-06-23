#ifndef WORDFREQ2
#define WORDFREQ2
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lowertext.h"
#include "rmstopwords.h"
#include "uniquekw.h"
#include "wordstats.h"
#include "createstring.h"
#include "copypastestring.h"
#include "strippunc.h"
#include "quicksort2.h"
#include "intarraycheck.h"

char * wordfreq2(char *text, char *keywordorder) {
	int i;
	printf("\nTEXT - %s\n", text);
	lowercase(text);
	printf("\nLowered - %s\n", text);

	char *puncfree = (char*)calloc(300000, sizeof(char));
	puncfree = strippunc(text, puncfree);
	printf("\nPuncfree - %s\n", puncfree);

	cleantext(puncfree);
	printf("\nClean - %s\n", puncfree);
	
	//Returns string with unique words only!!!
	uniquestrings(puncfree);
	printf("\nUwords - %s\n", puncfree);

	char *puncfreespacefree = (char*)calloc(300000, sizeof(char));
	int space = 0;
	printf("\n============== SPACER ===============\n");
	int incr_spacefree = 0;
	for (i = 0; i < strlen(puncfree); i++) {
		if (puncfree[i] == ' ') {
			space = 1;
		} else {
			if (space == 1)
			{	
				 puncfreespacefree[incr_spacefree] = ' ';
				 ++incr_spacefree;
				 puncfreespacefree[incr_spacefree] = puncfree[i];
				 ++incr_spacefree;
				 space = 0;
			} else {
				puncfreespacefree[incr_spacefree] = puncfree[i];
				++incr_spacefree;
			}
		}
	}
	return puncfreespacefree;
};
#endif