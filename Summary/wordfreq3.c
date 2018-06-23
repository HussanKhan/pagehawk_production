#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lowertext.h"
#include "rmstopwords.h"
#include "uniquewords.h"
#include "wordstats.h"
#include "createstring.h"
#include "copypastestring.h"
#include "strippunc.h"
#include "quicksort2.h"
#include "intarraycheck.h"
#include "unregspacerm.h"

int main () {
	char *text = (char*)calloc(200000, sizeof(char));
	text = "for a game so focused on presenting a seamless interactive cinematic story, the most striking thing about detroit: become human is its exposed seams. like the world’s most slickly produced choose-your-own-adventure book, the latest david cage game lets you play with narrative conventions and mess with the inherent connective tissue of the story in some intriguing ways. but that underlying story ends up so fragmented, so poorly executed, and so clunkily written that it’s very difficult to appreciate the narrative playspace.";
	
	char *tempword = (char*)calloc(200, sizeof(char));
	int words = wordcount(text);
	int arr[words + 1][2];
	int *se = &arr[0][0];
	uniquewords(text, se);
	int start = 0;
	int end = 0;

	for (int i = 0; i < words; i++)
	{	
		start = *(se + i);
		end = *(se + i + 1);
		if (end - start > 2) {
			printf("\nSTART %d\n", start);
			printf("\nEND %d\n", end);
			tempword = makestring(start, end, text);
			printf("\nWORD %s\n", tempword);
			printf("\n");
		}
	}

	// printf("\nSTART %d\n", *(se + 0));
	// printf("\nEND %d\n", *(se + 1));
	// tempword = makestring(*(se + 0), *(se + 1), text);
	// printf("\nWORD %s\n", tempword);

	// printf("\nSTART %d\n", *(se + 4));
	// printf("\nEND %d\n", *(se + 5));
	// tempword = makestring(*(se + 4), *(se + 5), text);
	// printf("\nWORD %s\n", tempword);

	// printf("\nSTART %d\n", *(se + 6));
	// printf("\nEND %d\n", *(se + 7));
	// tempword = makestring(*(se + 6), *(se + 7), text);
	// printf("\nWORD %s\n", tempword);

	// printf("\nSTART %d\n", *(se + 8));
	// printf("\nEND %d\n", *(se + 9));
	// tempword = makestring(*(se + 8), *(se + 9), text);
	// printf("\nWORD %s\n", tempword);

	return 0;
}