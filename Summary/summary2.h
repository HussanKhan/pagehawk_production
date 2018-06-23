#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "wordstats.h"
#include "copypastestring.h"
#include "keywords2.h"

const int ratio = ((15*15)/5);
//Returns a summary of given text in string
char * summary2(char *text, char *completed) {
	int i, k;

	char *keys[100];

	keywords2(text, keys, 15);

	// long long int start = 0;
	// long long int end;
	// long long int length = strlen(text);
	// int addins = 0;
	// long long int lastpos = 0;
	// char *thesent;
	// int occs;
	// int score;

	// char *sents[6];

	// for (i = 0; i < length; i++) {
	// 	if (text[i] != '.') {

	// 	} else {
	// 		end = i;
	// 		start = start;
	// 		if (end - start > 1) {
	// 			thesent = makestring(start, end, text);
	// 			printf("\nSENT: %s\n", thesent);
	// 			for (k = 0; k < 5; k++) {	
	// 				occs = findpattern(thesent, *(keys + k));
	// 				score = score + (occs*(5 - k));
	// 			}

	// 			if (score > ratio) {
	// 				*(sents + addins) = makestring(start, end, text);
	// 				++addins;
	// 			if (addins > 4) {
	// 				break;
	// 				}
	// 			}
	// 		}
	// 	}
	// 	score = 0;
	// 	start = i + 1;
		
	// }

	// for (i = 0; i < addins - 1; ++i)
	// {
	// 	transferstring(*(sents + i), completed, lastpos);#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "createstring.h"
#include "StringCompare.h"
#include "unregspacerm.h"
#include "strippunc.h"
#include "lowertext.h"
#include "rmstopwords.h"
#include "quicksort2.h"
#include "intarraycheck.h"
#include "wordstats.h"

void * keywords2 (char *text, char *storage[], int limit) {
	// 	lastpos = lastpos + (strlen(*(sents + i)));
	// }
	return completed;
};