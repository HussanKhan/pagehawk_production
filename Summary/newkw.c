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


int main() {
	char text[] = "In our opinion, the best webcam you can buy for streaming is the Logitech C992x, it delivers high frame per second video and provides you with high quality video.  And finally, we’ve watched hours of webcam quality tests to determine which webcam provides the best quality for streaming.  Having high sound quality while streaming is almost as important as video quality, so consider getting a dedicated microphone for streaming.  Our runner up for the best streaming webcam is the Logitech C920, this webcam is ridiculously popular.  This webcam has the same video quality as a standalone camcorder, with crisp video and great color balance.";
	long long int i, s;
	// remove punc from text
	strippunc(text);

	// lower all text
	lowercase(text);

	// remove stopwords from text
	cleantext(text);

	//Now return normal spacing
	char *oktext = (char*)calloc(strlen(text), sizeof(char));
	unregspacerm(text, oktext);

	long long int start = 0;
	long long int end = 0;
	long long int length = strlen(oktext);
	long long int lastindex = 0;

	char *uwords[100 + 1];

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

	struct word key[size_of_uwords];
	int scores[size_of_uwords];
	int arryind = 0;
	long int curr = 0;

	int addins = 0;

	for (i = 0; i < length; i++) {
		if (oktext[i] != ' ') {

		} else {

			end = i - 1;
			start = start;
			
			if (end - start > 2) {
				tempw = makestring(start, end, oktext);
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
		start = i + 1;
	}
};

	//Fills key and scores
	for (i = 0; i < size_of_uwords; i++)
	{	
		curr = (int)findpattern(oktext, *(uwords + i));
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
}