#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lowertext.h"
#include "wordstats.h"
#include "copypastestring.h"
#include "quicksort2.h"
#include "intarraycheck.h"
#include "sentences.h"
#include "keywords2.h"

//Returns a summary of given text in string
char * summary(char *text, char *completed) {
	//Stores text with proper caps in wcaps array, for later referance 
	//Creates new data
	//Pure Copy
	int s, k, se, i, w, ke;
	int sentnum = sentcounter(text);
	char *wcaps[sentnum + 1];
	sentences(text, wcaps);

	//For keyword Searching
	char *storage[sentnum + 1];
	int passed;
	passed = sentences(text, storage);

	//Stores keywords in lowercase
	char *keys[wordcount(text) + 1];



	//Fills keys
	keywords2(text, keys, 15);

	//Stores index of sentence in storage, and score
	struct sentscore
	{
		int index;
		long long int score;
	};

	//Array for above struct
	struct sentscore final[passed + 1];

	//Array of all unique scores
	//will be sorted from greatest to lowest
	int scorearr[passed];

	//Fills final array and assigns score
	int occs = 0;
	long long int score = 0;
	int sentincr = 0;
	char *thesent;
	long int arryind = 0;
	for (s = 0; s < passed - 1; s++)
	{	
		thesent = *(storage + s);
		for (k = 0; k < 15; k++)
		{	
			occs = findpattern(thesent, *(keys + k));
			score = score + (occs*(15 - k));
		}

		if (score > 0) {
			final[sentincr].index = (int)s;
			final[sentincr].score = (int)score;

			//If duplicte number in uoccurance, don't include
			if (arraycheck(scorearr, score, arryind) == 0)
			{
				scorearr[arryind] = score;
				++arryind;
			}
			++sentincr;
			occs = 0;
			score = 0;
		}
		
	}

	//Sorts scores from greatest to lowest
	quicksort(scorearr, 0, arryind);

	//Creates string and fills completed
	int addins = 0;
	long long int lastpos = 0;
	int lim = (arryind/3);
	for (se = 0; se < sentincr; se++)
		{	
			if (addins > 4)
			{
				break;
				}
			if (final[se].score > scorearr[lim])
			{
				{	
					transferstring(*(wcaps + final[se].index), completed, lastpos);
					lastpos = lastpos + strlen(*(wcaps + final[se].index));
					++addins;
				}
			}
		}

	//free memory //////////////////////////////////

	//freeing sentences
	for (i = 0; i < passed; ++i)
	{
		free(storage[i]);
	}

	//freeing original sentences
	for (w = 0; w < passed; ++w)
	{
		free(wcaps[w]);
	}

	//free keywords
	for (ke = 0; ke < 15; ++ke)
	{
		free(keys[ke]);
	}

	return completed;
};