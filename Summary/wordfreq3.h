#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lowertext.h"
#include "rmstopwords.h"
#include "uniquewords.h"
#include "wordstats.h"
#include "createstring.h"
#include "copypastestring.h"
#include "strippunc.h"
#include "quicksort2.h"
#include "intarraycheck.h"
#include "unregspacerm.h"
#include "StringCompare.h"

//This fills a given array with keywords from most important to least important
char * wordfreq3 (char *text, char *completed) {
	// //Now remove punc from text
	strippunc(text);

	// // First lower all text
	lowercase(text);

	//Now remove stopwords from text
	cleantext(text);

	//Now return normal spacing
	char *oktext = (char*)calloc(strlen(text), sizeof(char));
	unregspacerm(text, oktext);

	//vvvvvvv Create string of unique text only
	long long int words = wordcount(oktext);
	
	//Array of indexes for each word, start and end
	long long int arr[words + 1][2];
	long long int *se = &arr[0][0];

	long long int passed = 0;
	//Appending arr through se
	passed = uniquewords(oktext, se);
	
	long long int start = 0;
	long long int end = 0;

	//Array of pointers to address of all strings in text
	char *tempword[passed + 1];

	//Filling array of points with address if string
	int incr_temp = 0;
	for (int i = 0; i < passed + 1; i++)
	{	
		start = *(se + i);
		end = *(se + i + 1);
		if (end - start > 2) {
			*(tempword + incr_temp) = makestring(start, end, oktext);
			++incr_temp;
		}
	}

	//Stores Index of unique words in tempword
	char *uwords[incr_temp + 1];

	int size_of_uwords = 0;

	//To append of not to append, def is append
	int append = 1;
	//Loops through tempwords, and compares to words stored in uwords, if word not in uwords, append.
	for (int w = 0; w < incr_temp; w++)
	{	
		if (size_of_uwords != 0) {
			for (int s = 0; s < size_of_uwords; s++) {
			if (comparestr(*(uwords + s), *(tempword + w)) != 0) {
				append = 0;
			} 
			}
		}

		if (append == 1)
		{
			*(uwords + size_of_uwords) = *(tempword + w);
			++size_of_uwords;
		} else {
			append = 1;
		}
	}

	// Stores index and wordcount for each word in words
	struct wordwcount {
		long long int index;
		long long int count;
	};

	struct wordwcount keycount[size_of_uwords + 1];

	//Some words have the same occurance, so this array only stores unique number values
	int uoccurance[size_of_uwords];
	int *uocchandle = uoccurance;
	int curr = 0;

	//Fills keycount
	long long int lastindex = 0;
	int arryind = 0;
	for (int k = 0; k < size_of_uwords; k++)
	{	
		curr = (int)findpattern(oktext, *(uwords + k));
		keycount[lastindex].index = k;
		keycount[lastindex].count = curr;
		++lastindex;

		//If duplicte number in uoccurance, don't include
		if (arraycheck(uocchandle, curr, arryind) == 0)
		{
			uoccurance[arryind] = curr;
			++arryind;
		}
	}

	free(oktext);
	
	//Sorts from high to low
	quicksort(uocchandle, 0, arryind);
	
	int addins = 0;
	long long int lastpos = 0;

	for (int p = 0; p < arryind + 1; p++)
	{
		for (int g = 0; g < lastindex; g++)
		{	
			if (addins > 20) {
				break;
			}
			if (uoccurance[p] == keycount[g].count)
			{
				transferstring(*(uwords + keycount[g].index), completed, lastpos);
				lastpos = lastpos + strlen(*(uwords + keycount[g].index));
				++addins;
			}
		}
	}


	return completed;
};