#ifndef STRINGCOMPARE
#define STRINGCOMPARE
#include <stdio.h>
#include <string.h>

// Return 1 if match
int comparestr (char *word1, char *word2) {
	int result = 1;
	int miss = 0;
	
	for (int i = 0; word1[i] != '\0' || word2[i] != '\0'; ++i)
	{
		if (word1[i] != word2[i])
		{
			++miss;

			if (miss > 2)
			{	
				return 0;
			} 
			
		}
	}
	return result;
};
#endif