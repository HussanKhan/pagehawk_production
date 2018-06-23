#include <stdio.h>
#include "eachsent.h"
#include "wordstats.h"
#include "createstring.h"

//This fills a given array with keywords from most important to least important
int sentences (char *oktext, char *storage[]) {
	long long int start = 0;
	long long int end = 0;
	long long int length = strlen(oktext);
	int incr_temp = 0;

	for (long long int i = 0; i < length; i++) {
		if (oktext[i] != '.') {

		} else {

		end = i;
		start = start;

		if (end - start > 1) {
			*(storage + incr_temp) = makestring(start, end, oktext);
			++incr_temp;
		}

		start = i + 1;
		}
	}
	return incr_temp;
};