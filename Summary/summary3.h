#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "createstring.h"
#include "copypastestring.h"
#include "wordstats.h"
#include "StringCompare.h"
#include "strippunc.h"
#include "findpat.h"
#include "stopwordcheck.h"
#include "quicksort2.h"

char * summary3 (char *text, char *comp) {
	//////////////////////////////////// Extract /////////////////////////////////////////////////////////
	//Needed to extract each word
	long long int start = 0;
	long long int end;
	long long int i, u, us, p, un, t, k;
	long long int incrunique = 0;
	long long int textlen = 3*((strlen(text))/4);

	//Needed to extract each sentence
	long long int sentstart = 0;
	long long int sentend;
	long long int incr_sent = 0;
	long long int numsent = sentcounter(text);
	long long int sentarray[numsent][2];
	//////////Bound by index/////////////
	long long int numwords = wordcount(text);
	char *uniquewords[numwords];
	long long int count[numwords];
	int sortscore[numwords];
	int *ss = &sortscore[0];
	///////////////////////////
	
	char *tempword;
	long long int append = 1;
	long long int scoreapp = 1;
	long long int scoreincre = 0;

	//Extracts each word
	for (i = 0; i < textlen; ++i) {
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
			
			sentend = i + 1;
			sentstart = sentstart;

			if (sentend - sentstart > 1) {
				sentarray[incr_sent][0] = sentstart;
				sentarray[incr_sent][1] = sentend;
				++incr_sent;
			}

			sentstart = i + 1;
		} 
	}

	/////////////Ordering words//////////////////////

	//Sorting scores from greatest to least
	quicksort(ss, 0, scoreincre);

	//Store indexes only
	long long int uniqueindex[16];
	long long int incrindex = 0;
	for (p = 0; p < scoreincre; ++p)
	{	
		if (incrindex > 15)
				{
					break;
				}
			for (un = 0; un < incrunique; ++un)
			{
				if (sortscore[p] == count[un]) {
					uniqueindex[incrindex] = un;
					++incrindex;
				}
				if (incrindex > 15)
				{
					break;
				}
			}
	}

	//////////////////Scoring sentences////////////////////////
	/////////////////Making Summary////////////////////////////
	long long int incr_store = 0;
	char *store_comp_sent_address[numsent];
	long long int score = 0;
	long long int sent_num = 0;
	long long int occs = 0;
	long long int lastindex = 0;

	for (t = 0; t < incr_sent; t++)
	{	
		store_comp_sent_address[incr_store] = makestring(sentarray[t][0], sentarray[t][1], text);

		// //Score Sentence 
		for (k = 0; k < 15; k++)
		{	
			occs = findpattern(store_comp_sent_address[t], uniquewords[uniqueindex[k]]);
			score = score + ((15 - k)*occs);
		}

		//Check for score lower limit
		if (score > 25)
		{
			transferstring(store_comp_sent_address[t], comp, lastindex);
			lastindex = lastindex + (sentarray[t][1] - sentarray[t][0]);
			++sent_num;
		}

		//Break if sentence limit reached
		if (sent_num > 4)
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
};