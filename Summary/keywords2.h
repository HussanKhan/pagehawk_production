#include <stdio.h>
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
	long long int i, s;
	// remove punc from text
	strippunc(text);

	// remove stopwords from text
	cleantext(text);

	//Now return normal spacing
	// char *text = (char*)calloc(strlen(text), sizeof(char));
	// unregspacerm(text, text);

	long long int start = 0;
	long long int end = 0;
	long long int length = strlen(text);
	long long int lastindex = 0;

	char *uwords[wordcount(text)];

	int size_of_uwords = 0;

	//To append of not to append, def is append
	int append = 1;
	//Loops through tempwords, and compares to words stored in uwords, if word not in uwords, append.
	char *tempw;

	struct word
	{
		int wordindex;
		int value;
	};

	int arryind = 0;
	long int curr = 0;

	int addins = 0;

	for (i = 0; i < length - 1; i++) {
		if (text[i] != ' ') {

		} else {

			end = i - 1;
			start = start;
			
			if (end - start > 2) {
				tempw = makestring(start, end, text);
				if (size_of_uwords != 0) {
					for (s = 0; s < size_of_uwords; s++) {
						if (comparestr(*(uwords + s), tempw) != 0) {
						append = 0;
					} 
				}
			}

			if (append == 1) {
				*(uwords + size_of_uwords) = &*tempw;
				++size_of_uwords;
			} else {
				append = 1;
			}
		}
	}
	start = i + 1;
};
	struct word key[size_of_uwords];
	int scores[size_of_uwords];
	//Fills key and scores
	for (i = 0; i < size_of_uwords; i++)
	{	
		curr = (int)findpattern(text, *(uwords + i));
		key[lastindex].wordindex = i;
		key[lastindex].value = curr;
		++lastindex;

		//If duplicte number in scores, don't include int
		if (arraycheck(scores, curr, arryind) == 0)
		{
			scores[arryind] = curr;
			++arryind;
		}
	}

	//Sorts from greatest to lowest
	quicksort(scores, 0, arryind);

	for (i = 0; i < arryind + 1; i++)
	{
		for (s = 0; s < lastindex; s++)
		{	
			if (scores[i] == key[s].value)
			{	
				char *tword = (char*)calloc(strlen(*(uwords + key[s].wordindex)) + 1, sizeof(char)); 
				tword = *(uwords + key[s].wordindex);
				*(storage + addins) = &*tword;
				++addins;
				if (addins > limit) {
				break;
				}
			}
		}
	}
	return NULL;
};