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

int main () {
	char *text = (char*)calloc(100000, sizeof(char));
	text = "Messages in iCloud has been in the works for a long time, and it has appeared and disappeared from various beta releases of Apple software. It was added in iOS 11.4 earlier this week, and now it's supported on Macs. The feature allows you to store communications you receive and send within the Messages app—plus associated file attachments—in iCloud to save space on your local device. It also means that changes like deleting messages are propagated across devices, and a new Mac that is logged into your iCloud account will immediately have access to your Messages history. 10.13.5 includes some security updates as well, which Apple has detailed on its support website. For example, the update addresses vulnerabilities in graphics drivers for Intel and AMD chips that allowed applications to read restricted memory, and it fixes a vulnerability in the Mail app that allowed attackers to access the contents of encrypted emails. The update follows 10.13.4, which among other things added official external GPU support and new privacy features—though we found that eGPU support still has a way to go. Apple is expected to announce the details of macOS 10.14, a more major release expected in September, at its Worldwide Developers Conference on June 4.";
	char *comp = (char*)calloc(100000, sizeof(char));

	//////////////////////////////////// Extract /////////////////////////////////////////////////////////
	//Needed to extract each word
	int start = 0;
	int end;
	int i, u, us, p, un, t, k;
	int incrunique = 0;

	//Needed to extract each sentence
	int sentstart = 0;
	int sentend;
	int incr_sent = 0;
	char *storage[1000];
	int sentarray[1000][2];
	//////////Bound by index/////////////
	char *uniquewords[1000];
	int count[1000];
	int sortscore[1000];
	int *ss = &sortscore[0];
	///////////////////////////
	
	char *tempword;
	int append = 1;
	int scoreapp = 1;
	int scoreincre = 0;

	//Store stopwords to delete
	char *spwords[1000];
	int incrsp = 0;

	//Extracts each word
	for (i = 0; text[i] != '\0'; ++i) {
		if (text[i] == ' ') {
			end = i - 1;
			start = start;

			tempword = makestring(start, end, text);
			strippunc(tempword);

			//First checks to see if it's a stopword, proceeds if NOT stopword
			if (stopwordcheck(tempword) == 0) {

				//Check to see if word already in unique words
				for (u = 0; u < incrunique; ++u) {
					if (comparestr(*(uniquewords + u), tempword) != 0) {
						append = 0;
					}
				}

				//Checking to see if match found, if not, append list
				if (append == 1) {
					*(uniquewords + incrunique) = &*tempword;
					count[incrunique] = findpattern(text, &*tempword);
					
					//Making sure only unique values stored in score
					for (us = 0; us < scoreincre; us++)
					{
						if (sortscore[us] == count[incrunique])
						{
							scoreapp = 0;
						}
					}

					//If no match found in array, append
					if (scoreapp == 1)
					{
						sortscore[scoreincre] = count[incrunique];
						++scoreincre;
					}
					scoreapp = 1;
					++incrunique;
				} 
					
			} else {free(tempword);}
			append = 1;
			start = end + 2;
		} 

		//Store Sentences
		if (text[i] == '.' && (text[i + 1] == ' ' || text[i + 1] == '\0')) {
			
			sentend = i;
			sentstart = sentstart;

			if (sentend - sentstart > 1) {
				sentarray[incr_sent][0] = sentstart;
				sentarray[incr_sent][1] = sentend;
				++incr_sent;
			}

			sentstart = i + 2;
		} 
	}

	/////////////Ordering words//////////////////////

	//Sorting scores from greatest to least
	quicksort(ss, 0, scoreincre);

	//Store indexes only
	int uniqueindex[1000];
	int incrindex = 0;
	for (p = 0; p < scoreincre; ++p)
	{
			for (un = 0; un < incrunique; ++un)
			{
				if (sortscore[p] == count[un]) {
					uniqueindex[incrindex] = un;
					++incrindex;
				}
			}
	}

	//////////////////Scoring sentences////////////////////////
	/////////////////Making Summary////////////////////////////
	int incr_store = 0;
	char *store_comp_sent_address[100];
	int score = 0;
	int sent_num = 0;
	int occs = 0;
	int lastindex = 0;

	for (t = 0; t < incr_sent; t++)
	{	
		store_comp_sent_address[incr_store] = makestring(sentarray[t][0], sentarray[t][1], text);

		// //Score Sentence 
		for (k = 0; k < 5; k++)
		{	
			occs = findpattern(store_comp_sent_address[t], uniquewords[uniqueindex[k]]);
			score = score + ((5 - k)*occs);
		}

		//Check for score lower limit
		if (score > 8)
		{
			transferstring(store_comp_sent_address[t], comp, lastindex);
			lastindex = lastindex + (sentarray[t][1] - sentarray[t][0]);
			++sent_num;
		}

		//Break if sentence limit reached
		if (sent_num > 2)
		{
			break;
		}

		score = 0;
		++incr_store;
	}
	comp[lastindex] -= '\0';

	//Free memory
	for (i = 0; i < incrunique; i++)
	{
		free(uniquewords[i]);
	}

	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	return comp;
}