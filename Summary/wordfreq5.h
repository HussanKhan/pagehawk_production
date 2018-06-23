#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lowertext.h"
#include "rmstopwords.h"
#include "wordstats.h"
#include "createstring.h"
#include "copypastestring.h"
#include "strippunc.h"
#include "quicksort2.h"
#include "intarraycheck.h"
#include "unregspacerm.h"
#include "StringCompare.h"
#include "sentences.h"

//Returns a summary of given text in string
char * wordfreq5 (char *text, char *completed) {
	char *storage[sentcounter(text) + 1];

	sentences(text, storage);
	
	int addins = 0;
	long long int lastpos = 0;
	for (int g = 0; g < sentcounter(text); g++)
		{	
			transferstring(*(storage + g), completed, lastpos);
			lastpos = lastpos + strlen(*(storage + g));
			++addins;
		}

		printf("\n%s\n", *(storage + 0));

		printf("\n%s\n", *(storage + 1));

		printf("\n%s\n", *(storage + 2));

	return completed;
};