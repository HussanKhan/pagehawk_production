#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "createstring.h"
#include "copypastestring.h"
#include "StringCompare.h"
#include "strippunc.h"
#include "findpat.h"
#include "stopwordcheck.h"
#include "quicksort2.h"
#include "wordstats.h"
#include "intarraycheck.h"
#include "rmstopwords.h"
#include "unregspacerm.h"

//Checks if string is unique to array
int stringuniquecheck (char *arr[], char *word, int arrlen) {
	int w;
	for (w = 0; w < arrlen; w++) {
		if (comparestr(arr[w], word) == 1) {
			return 0;
		}
	}
	return 1;
};

//Scores each given sentence
int sentencescore(char *sentence, char *keywords[], int keywordlen) {
	int score = 0;
	int s = 0;
	int nummatches = 0;
	for (s = 0; s < keywordlen; s++) {
		nummatches = findpattern(sentence, keywords[s]);
		score = score + (((keywordlen - s)*nummatches)/3);
	}

	return (score);
};

char * summary6 (char *text, char *summy, int limit) {
	// printf("\n- Program started...\n");
	
	// printf("\n- Allocating memory...\n");

	//For array creation
	int tlen = strlen(text);
	int wordc = (tlen/6);
	int scount = (tlen/10);

	//For looping
	int i, k;
	int word_start = 0;
	int word_end;

	int sent_start = 0;
	int sent_end;

	//For storing words and sentences
	int incr_eachword = 0;
	char *tempword;
	char *each_word[wordc];
	int each_word_count[wordc];

	int incr_eachsent = 0;
	char *eachsentence[scount+1];
	int sentscores[scount+1];
	int sentlen[scount+1];

	// printf("\n- Tokenizing sentences...\n");
	for (i = 0; text[i] != '\0'; i++) {
		//Stop when sentence discovered (needed for later scoring)
		if ((text[i] == '.' || text[i] == '?') && (text[i + 1] == ' ' || text[i + 1] == '\0')) {
			sent_end = i;
			sent_start = sent_start;

			eachsentence[incr_eachsent] = makestring(sent_start, sent_end, text);
			sentlen[incr_eachsent] = (sent_end - sent_start);
			++incr_eachsent;
			sent_start = sent_end + 2;
		}
	}	

	// printf("\n- Starting keyword search...\n");
	for (i = 0; text[i] != '\0'; i++) {

		//Stops if word discovered
		if (text[i] == ' ') {
			word_end = i - 1;
			word_start = word_start;

			//Creating instance of word;
			tempword = makestring(word_start, word_end, text);

			//Removing puncuation 
			strippunc(tempword);

			//Checks if word is unique to array, only unique words are appended.
			if (stringuniquecheck(each_word, tempword, incr_eachword) == 1) {
				each_word[incr_eachword] = &*tempword;
				++incr_eachword;
			} else {
				free(&*tempword);
			}

			word_start = word_end + 2;
		}

	}

	// printf("\n- Find occurrence for each unique word...\n");
	//For sorting later in future, sorts only unique counts
	int wordhandler[wordc];
	int count = 0;
	int sizeofwh = 0;
	int passedwords = 0;
	for (i = 0; i < incr_eachword; i++) {
		if (stopwordcheck(each_word[i]) == 0) {
			count = findpattern(text, each_word[i]);
			each_word_count[i] = count;
			++passedwords;
		} else {
			each_word_count[i] = 0;
		}
		//Makes sure to only store unique values in wordhandle
		if (arraycheck(wordhandler, count, sizeofwh) == 0) {
			wordhandler[sizeofwh] = count;
			++sizeofwh;
		}
	}

	//Sorting scores
	quicksort(wordhandler, 0, sizeofwh);

	// printf("\n- Sorting keywords from greatest to least valuable...\n");
	//Stores keywords from most valuable to least
	char *sortedkw[passedwords + 1];
	int incr_scores = 0;
	int numofkeys = 10;
	for (i = 0; i < numofkeys; i++) {
		for (k = 0; k < passedwords; k++)
		{
			if (wordhandler[i] == each_word_count[k]) {
				sortedkw[incr_scores] = each_word[k];
				++incr_scores;
				break;
			}
		}
	}

	// printf("\n- Scoring each sentence and sorting...\n");
	int sentscoremap[incr_eachsent];
	int sentvalue = 0;
	int sizeofsentscore = 0;
	for (i = 0; i < incr_eachsent; i++) {
		sentvalue = sentencescore(eachsentence[i], sortedkw, incr_scores);
		sentscores[i] = sentvalue;

		if (arraycheck(sentscoremap, sentvalue, sizeofsentscore) == 0) {
			sentscoremap[sizeofsentscore] = sentvalue;
			++sizeofsentscore;
		}
	}

	quicksort(sentscoremap, 0, sizeofsentscore);

	// printf("\n- Creating summery...\n");
	int lastindex = 0;
	int addedsents = 0;
	int lowerlimit = sentscoremap[(sizeofsentscore - (sizeofsentscore/3))];
	for (i = 0; i < incr_eachsent; i++)
	{	
		if(addedsents > limit){break;}
		if (sentscores[i] > lowerlimit)
		{
			transferstring(eachsentence[i], summy, lastindex);
			lastindex = lastindex + sentlen[i]+2;
			++addedsents;
		}
	}

	summy[lastindex] = '\0';

	for (i = 0; i < incr_eachword; ++i)
	{
		printf("\nWORD: -%s-\n", each_word[i]);
	}

	// printf("\n- Freeing allocated memory...\n");
	
	//Free unique words
	for (i = 0; i < incr_eachword; ++i)
	{
		free(each_word[i]);
	}

	//Free sentences
	for (i = 0; i < incr_eachsent; ++i)
	{
		free(eachsentence[i]);
	}

	// free(keysearch);
	
	// printf("\n- Complete!\n");
	return summy;
}