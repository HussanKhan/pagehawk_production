#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lowertext.h"
#include "wordstats.h"
#include "copypastestring.h"
#include "quicksort2.h"
#include "intarraycheck.h"
#include "sentences.h"
#include "keywords.h"

//Returns a summary of given text in string
char * summary(char *text, char *completed) {
	//Stores text with proper caps in wcaps array, for later referance 
	//Creates new data
	int sentnum = sentcounter(text);
	char *wcaps[sentnum + 1];
	sentences(text, wcaps);

	//Lowers all letter in main text for later comparison with keywords
	lowercase(text);

	//Stores each sentence in lowercase
	char *storage[sentnum + 1];

	//Stores keywords in lowercase
	char *keys[wordcount(text) + 1];

	//Fills storage
	int passed;
	passed = sentences(text, storage);

	//Fills keys
	keywords(text, keys, 20);

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
	for (int s = 0; s < passed - 1; s++)
	{	
		thesent = *(storage + s);
		for (int k = 0; k < 20; k++)
		{	
			occs = findpattern(thesent, *(keys + k));
			score = score + (occs*(20 - k));
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
	int tscore = 0;
	for (int g = 0; g < arryind; g++) {

		tscore = scorearr[g];

		for (int se = 0; se < sentincr; se++)
		{
			if (addins > 4)
			{
				break;
			}
			if (final[se].score == tscore)
			{
				{	
					transferstring(*(wcaps + final[se].index), completed, lastpos);
					lastpos = lastpos + strlen(*(wcaps + final[se].index));
					++addins;
				}
			}
		}
	};

	//free memory //////////////////////////////////

	//freeing sentences
	for (int i = 0; i < passed; ++i)
	{
		free(storage[i]);
	}

	//freeing original sentences
	for (int w = 0; w < passed; ++w)
	{
		free(wcaps[w]);
	}

	//free keywords
	for (int ke = 0; ke < 20; ++ke)
	{
		free(keys[ke]);
	}

	return completed;
};