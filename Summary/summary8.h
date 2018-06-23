#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "createstring.h"
#include "findpat.h"
#include "strippunc.h"
#include "copypastestring.h"
#include "StringCompare.h"

int summary8(char *text, char *summary, int limit) {
	//printf("\n- Program started...\n");

	//printf("\n- Memory Allocation...\n");

	int arraysize = strlen(text);
	arraysize = (arraysize/6);
	
	int threshold = (arraysize/5);

//////Master list of known words and counts.
//////Before searching text, search this
	char *each_word[arraysize];
	int each_word_count[arraysize];
	int mast_length = 0;
	int num_words = 1;
	int i = 0;

	int sent_passed = 0;
	int lastindex = 0;

	int sent_start = 0;
	int sent_end = 0;
	char *eachsentence[arraysize/10];
	int sentlen[arraysize/10];
	int sentscore[arraysize/10];
	int maxscore = 0;
	int incr_eachsent = 0;
////////////////////////////////////////////

	//printf("\n- Creating functions...\n");

/////Checks if string is unique to array, if not returns location of found match in given array
	int stringuniquecheck (char *arr[], char *word, int arrlen) {
		int w;
		for (w = 0; w < arrlen; w++) {
			if (comparestr(arr[w], word) == 1) {
				return w;
			}
		}
		//Return this if match NOT FOUND
		return 10101;
	};
///////////////////////////////////////////////////////////////////////

//////Tells how many common words are in each sentence
	int scoresentence (char *sentence1, int index) {
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

				//Checks if word in master array, if match found extracts value
				int value = stringuniquecheck(each_word, each_word[mast_length], mast_length-1);
				if (value != 10101) {
					score = score + each_word_count[value];
					free(&*each_word[mast_length]);
				} else {
					fpat = findpattern(text, each_word[mast_length]);
					score = score + fpat;
					each_word_count[mast_length] = fpat;
					++mast_length;
				}
			word_start = word_end + 2;
		}
	}

	return score;
};
////////////////////////////////////////////////////////////////////////////////

	//Extract Sentences from text
	//printf("\n- Tokenizing text into sentences...\n");
		for (i = 0; (text[i] != '\0' && sent_passed < limit); i++) {
			//Stop when sentence discovered (needed for later scoring)
			if ((text[i] == '.' || text[i] == '?') && (text[i + 1] == ' ' || text[i + 1] == '\0')) {
				sent_end = i;
				sent_start = sent_start;

				//Sentence stored in array, malloc copy created
				eachsentence[incr_eachsent] = makestring(sent_start, sent_end, text);

				//Score sentence after it has been created, and store in sent_score
				sentscore[incr_eachsent] = scoresentence(eachsentence[incr_eachsent], incr_eachsent);

				//Record Sentence len for later summary making
				sentlen[incr_eachsent] = (sent_end - sent_start);

				//If score is high enough, transfer to summary

				if (sentscore[incr_eachsent] > threshold) {
					transferstring(eachsentence[incr_eachsent], summary, lastindex);
					lastindex = lastindex + (sentlen[incr_eachsent]) + 2;
					summary[lastindex] = ' ';
					++sent_passed;
				}

				//Finds max score while sorting
				if (sentscore[incr_eachsent] > maxscore) { maxscore = sentscore[incr_eachsent];};

				++incr_eachsent;
				sent_start = sent_end + 2;
			}
		}

	// int threshold = ((maxscore/10)*3);


	//printf("\n- Creating summary...\n");

	// for (i = 0; sent_passed < limit; i++) {
	// 	if (sentscore[i] > threshold) {
	// 		transferstring(eachsentence[i], summary, lastindex);
	// 		lastindex = lastindex + (sentlen[i]) + 2;
	// 		summary[lastindex] = ' ';
	// 		++sent_passed;
	// 	}
	// }
	summary[lastindex] = '\0';
	//printf("\n- Freeing Memory...\n");
	for (i = 0; i < incr_eachsent; i++) {
		free(&*eachsentence[i]);
	}

	for (i = 0; i < mast_length; i++)
	{
		free(&*each_word[i]);
	}

	//printf("\n- Program Complete!\n");
	return 0;
}