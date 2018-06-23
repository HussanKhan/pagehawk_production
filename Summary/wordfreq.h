#ifndef WORDFREQ
#define WORDFREQ
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
#include "unregspacerm.h"

char * wordfreq(char *text, char *keywordorder) {

	lowercase(text);
	printf("\nLowered - %s\n", text);

	char *matchtest = (char*)calloc(300000, sizeof(char));
	matchtest = strippunc(text, matchtest);

	char *puncefreespace = (char*)calloc(300000, sizeof(char));
	puncefreespace = strippunc(text, puncefreespace);
	printf("\npuncefreespace - %s\n", puncefreespace);

	cleantext(puncefreespace);
	printf("\nClean - %s\n", puncefreespace);
	
	//Returns string with unique words only!!!
	uniquestrings(puncefreespace);
	printf("\nUwords - %s\n", puncefreespace);

	char *puncefree = (char*)calloc(300000, sizeof(char));
	unregspacerm(puncefreespace, puncefree);
	free(puncefreespace);
	//Ranking words from most common to least common
	struct wordvalue {
		int count;
		char word[300];
	};

	long int numwords = wordcount(puncefree) + 1;


	//Store words with counts
	struct wordvalue mainwords[numwords];

	//For finding word indexes in uword = unique words
	int i;
	int start = 0;
	int end;

	
	char *tempword = (char*)calloc(300, sizeof(char));
	char *tempword2 = (char*)calloc(300, sizeof(char));
	int values[numwords];

	int inc_words = 0;
	int passed = 0;

	//Goes through string of unique words and puncefreespace to fine occurances, and counts occurences 
	for(i = 0; i < (strlen(puncefree)); i++) {
		if (puncefree[i] != ' ') {
		} else {
		  end = i - 1;
		  start = start;
		  tempword = makestring(start, end, puncefree);
		  tempword2 = makestring(start, end, puncefree);
		  int occ = findpattern(matchtest, tempword2);
		  printf("\nWORD %s COUNT %d\n", tempword, occ);
		 	if (occ > 1)
		 	{
		 		transferstring(tempword, mainwords[inc_words].word, 0);
		    	mainwords[inc_words].count = occ;
		     	//Only increments if passed test
		    	inc_words = inc_words + 1;
		    	if (arraycheck(values, occ, passed) == 0)
		    	{
		    		values[passed] = occ;
		    		++passed;
		    	}; //if arraycheck
		 	}; //if occ check
		 	start = i + 1;
		}; //else
	}; //for

	// free(puncefreespace);
	// free(uwords);

	//Makes sure first word in string most freq
	quicksort(values, 0, passed);

	//Creating string to return
	int lastindex = 0;
	for (i = 0; i < passed + 1; i++) {
		for (int j = 0; j < inc_words + 1; ++j)
		{
			if (values[i] == mainwords[j].count)
			{	
				printf("\nWORD %s COUNT %d\n", mainwords[j].word, values[i]);
				transferstring(mainwords[j].word, keywordorder, lastindex);
				lastindex = lastindex + (strlen(mainwords[j].word));
			};
		};
	};

	return keywordorder;
	// return puncefreespace;
};
#endif