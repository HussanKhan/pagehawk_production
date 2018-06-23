#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "createstring.h"
#include "findpat.h"
#include "strippunc.h"
#include "quicksort2.h"
#include "copypastestring.h"

//Tells how many common words are in each sentence
int scoresentence (char *sentence1, int sentence1_index, int scorearray[], int sentscoresort[], char *text) {
	int score = 0;
	int i;
	int word_start = 0;
	int word_end;
	char *checkword;

	//Looping through sentence 1, for each word
	for (i = 0; sentence1[i] != '\0'; i++) {
		if (sentence1[i] == ' ') {
			word_end = i - 1;
			word_start = word_start;

			checkword = makestring(word_start, word_end, sentence1);
			strippunc(checkword);

			score = score + (findpattern(text, checkword));

			free(checkword);

			word_start = word_end + 1;
		}
	}
	scorearray[sentence1_index] = (int)score;
	sentscoresort[sentence1_index] = (int)score;
	return 0;
}

int main () {
	printf("\n- Program started...\n");

	printf("\n- Allocating memory...\n");
	char *text = (char*)calloc(10000, sizeof(char));
	text = "Messages in iCloud has been in the works for a long time, and it has appeared and disappeared from various beta releases of Apple software. It was added in iOS 11.4 earlier this week, and now it's supported on Macs. The feature allows you to store communications you receive and send within the Messages app—plus associated file attachments—in iCloud to save space on your local device. It also means that changes like deleting messages are propagated across devices, and a new Mac that is logged into your iCloud account will immediately have access to your Messages history. 10.13.5 includes some security updates as well, which Apple has detailed on its support website. For example, the update addresses vulnerabilities in graphics drivers for Intel and AMD chips that allowed applications to read restricted memory, and it fixes a vulnerability in the Mail app that allowed attackers to access the contents of encrypted emails. The update follows 10.13.4, which among other things added official external GPU support and new privacy features—though we found that eGPU support still has a way to go. Apple is expected to announce the details of macOS 10.14, a more major release expected in September, at its Worldwide Developers Conference on June 4.";
	char *summy = (char*)calloc(10000, sizeof(char));
	
	//For sentence tokenizing 
	int i;
	int sent_end;
	int sent_start = 0;
	int incr_eachsent = 0;
	int arraysize = (strlen(text)/6)/15;

	//Both bound by index
	char *eachsentence[arraysize]; // 6 = character in word, 15 = words in sentence
	int sentencescore[arraysize];
	int sentlen[arraysize];
	int sentscoresort[arraysize];
	int *pss = sentscoresort;

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
	for (i = 0; i < incr_eachsent; i++) {
		scoresentence(eachsentence[i], (i), sentencescore, sentscoresort, text);
	}

	printf("\n- Sorting scores...\n");
	quicksort(pss, 0, incr_eachsent);


	printf("\n- Creating summary...\n");
	int threshold = (incr_eachsent - (incr_eachsent/10)*3);
	int lastindex = 0;
	int sentpassed = 0;
	int sumlen = 4;
	for (i = 0; i < incr_eachsent; i++) {
		if (sentpassed >= 4) {
			break;
		}
		if (sentencescore[i] >= sentscoresort[threshold]) {
			transferstring(eachsentence[i], summy, lastindex);
			lastindex = lastindex + (sentlen[i]) + 2;
			++sentpassed;
		}
	}

	printf("\n- Test Results...\n");
	printf("\n-%s\n", summy);

	printf("\n- Freeing allocated memory...\n");
		for (i = 0; i < incr_eachsent; ++i) {
		free(eachsentence[i]);
	};

	printf("\n- Program Complete!\n");
	return 0;
}