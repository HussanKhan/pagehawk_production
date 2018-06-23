#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "createstring.h"
#include "findpat.h"
#include "strippunc.h"
#include "quicksort2.h"
#include "copypastestring.h"
#include "intarraycheck.h"
#include "StringCompare.h"
#include "stopwordcheck.h"


int summary7 (char *text, char *summy, int limit) {
	printf("\n- Program started...\n");

	printf("\n- Allocating memory...\n");
	
	//For sentence tokenizing 
	int arraysize = (strlen(text)/4)/10;
	int i;
	int sent_end;
	int sent_start = 0;
	int incr_eachsent = 0;

	//Both bound by index
	char *eachsentence[arraysize]; // 6 = character in word, 15 = words in sentence
	int sentencescore[arraysize];
	int sentlen[arraysize];
	int sentscoresort[arraysize];
	int *pss = sentscoresort;

//Checks if string is unique to array, if not returns location of found match in given array
int stringuniquecheck (char *arr[], char *word, int arrlen) {
	int w;
	for (w = 0; w < arrlen; w++) {
		if (comparestr(arr[w], word) == 1) {
			return w;
		}
	}
	return 777;
};

//Master list of known words and counts.
//Before searching text, search this
char *each_word[arraysize*2];
int each_word_count[arraysize*2];
int mast_length = 0;
int num_words = 1;

//Tells how many common words are in each sentence
int scoresentence (char *sentence1, char *text) {
	int score = 0;
	int i;
	int word_start = 0;
	int word_end;
	int fpat = 0;

	//Looping through sentence 1, for each word
	for (i = 0; sentence1[i] != '\0'; i++) {
		if (sentence1[i] == ' ') {
			word_end = i - 1;
			word_start = word_start;
			++num_words;
			each_word[mast_length] = makestring(word_start, word_end, sentence1);
			strippunc(each_word[mast_length]);

				//Checks if word in master array
				int value = stringuniquecheck(each_word, each_word[mast_length], mast_length-1);
				if (value != 777) {
					score = score + each_word_count[value];
				} else {
					fpat = findpattern(text, each_word[mast_length]);
					score = score + fpat;
					each_word_count[mast_length] = fpat;
					++mast_length;
				}

			free(&*each_word[mast_length]);

			word_start = word_end + 2;
		}
	}
	
	return score;
};

	printf("\n- Tokenizing into sentences...\n");
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

	
	printf("\n- Comparing and scoring sentences...\n");
	int score = 0;
	int pss_size = 0;
	for (i = 0; i < incr_eachsent; i++) {
		score = scoresentence(eachsentence[i], text);
		sentencescore[i] = score;
		if (arraycheck(pss, score, pss_size) == 0) {
			sentscoresort[pss_size] = score;
			++pss_size;
		}
	}

	printf("\n- Sorting scores...\n");
	quicksort(pss, 0, pss_size);


	printf("\n- Creating summary...\n");
	int threshold = (pss_size - (pss_size/10)*2);
	int lastindex = 0;
	int sentpassed = 0;

	for (i = 0; i < incr_eachsent; i++) {
		if (sentpassed >= limit) {
			break;
		} else if (sentencescore[i] >= sentscoresort[threshold]) {
			transferstring(eachsentence[i], summy, lastindex);
			lastindex = lastindex + (sentlen[i]) + 2;
			summy[lastindex] = ' ';
			++sentpassed;
		}
	}

	// printf("\n- Test Results...\n");
	// for (i = 0; i < mast_length; ++i)
	// {
	// 	printf("\nWORD: -%s- SCORE: %d\n", each_word[i], each_word_count[i]);
	// }

	printf("\n- Freeing allocated memory...\n");
	for (i = 0; i < incr_eachsent; ++i) {
		free(eachsentence[i]);
	};

	for (int i = 0; i < mast_length; ++i)
	{
		free(&*each_word[i]);
	}

	printf("\n- Program Complete!\n");
	return num_words;
}