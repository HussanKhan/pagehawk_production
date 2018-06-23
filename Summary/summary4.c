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

//Checks if string is unique to array
int stringuniquecheck (char *arr[], char *word, int arrlen) {
	int check = 1;
	int w;
	for (w = 0; w < arrlen; w++) {
		if (comparestr(arr[w], word) == 1) {
			check = 0;
		}
	}
	return check;
};

//Scores each given sentence
int sentencescore(char *sentence, char *keywords[], int keywordlen) {
	int score = 0;
	int s = 0;
	int nummatches = 0;
	for (s = 0; s< keywordlen; s++) {
		nummatches = findpattern(sentence, keywords[s]);

		score = score + (((keywordlen - s)*nummatches)/3);
	}

	return (score);
}

int main () {
	char *text = (char*)calloc(10000, sizeof(char));
	text = "Messages in iCloud has been in the works for a long time, and it has appeared and disappeared from various beta releases of Apple software. It was added in iOS 11.4 earlier this week, and now it's supported on Macs. The feature allows you to store communications you receive and send within the Messages app—plus associated file attachments—in iCloud to save space on your local device. It also means that changes like deleting messages are propagated across devices, and a new Mac that is logged into your iCloud account will immediately have access to your Messages history. 10.13.5 includes some security updates as well, which Apple has detailed on its support website. For example, the update addresses vulnerabilities in graphics drivers for Intel and AMD chips that allowed applications to read restricted memory, and it fixes a vulnerability in the Mail app that allowed attackers to access the contents of encrypted emails. The update follows 10.13.4, which among other things added official external GPU support and new privacy features—though we found that eGPU support still has a way to go. Apple is expected to announce the details of macOS 10.14, a more major release expected in September, at its Worldwide Developers Conference on June 4.";
	
	char *summy = (char*)calloc(10000, sizeof(char));

	printf("\n- Program started...\n");
	
	printf("\n- Allocating memory...\n");

	//For array creation
	int wordc = wordcount(text);
	int scount = sentcounter(text);

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

	printf("\n- Starting keyword search...\n");
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

		//Stop when sentence discovered (needed for later scoring)
		if ((text[i] == '.' || text[i] == '?') && (text[i + 1] == ' ' || text[i + 1] == '\0')) {
			sent_end = i;
			sent_start = sent_start;

			eachsentence[incr_eachsent] = makestring(sent_start, sent_end, text);
			
			++incr_eachsent;
			sent_start = sent_end + 2;
		}

	}

	printf("\n- Find occurrence for each unique word...\n");
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

	printf("\n- Sorting keywords from greatest to least valuable...\n");
	//Stores keywords from most valuable to least
	char *sortedkw[passedwords + 1];
	int incr_scores = 0;
	for (i = 0; i < (sizeofwh/2); i++) {
		for (k = 0; k < passedwords; k++)
		{
			if (wordhandler[i] == each_word_count[k]) {
				sortedkw[incr_scores] = each_word[k];
				++incr_scores;
			}
		}
	}

	printf("\n- Scoring each sentence and sorting...\n");
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
	// int lastindex = 0;
	// for (i = 0; i < incr_eachsent; i++)
	// {
	// 	if (sentscores[i] > sentscoremap[(sizeofsentscore/2)])
	// 	{
	// 		transferstring(eachsentence[i], summy, lastindex);
	// 		lastindex = lastindex + strlen(eachsentence[i]);
	// 	}
	// }
	// summy[lastindex] = '\0';
	// printf("\n%s\n", summy);

	printf("\nStarting text...\n");
	cleantext(text, summy);
	printf("\n%s\n", summy);

	printf("\n- Freeing allocated memory...\n");
	
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
	
	printf("\n- Complete!\n");
	
	return 0;
}
