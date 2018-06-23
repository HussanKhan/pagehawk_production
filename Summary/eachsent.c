#ifndef EACHSENT
#define EACHSENT
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "findpat.h"
#include "createstring.h"
#include "copypastestring.h"


//Returns starting and ending index of each sentence in string
int eachsent (char *content, long long int *arr) {

	long long int start = 0;
	long long int end = 0;
	long long int length = strlen(content);
	long long int lastindex = 0;

	for (long long int i = 0; i < length; i++) {
		if (content[i] != '.') {

		} else {

		end = i - 1;
		start = start;

		arr[lastindex] = start;
		++lastindex;
		arr[lastindex] = end;
		++lastindex;

		start = i + 1;
		}
	}
	lastindex = lastindex - 2;
	return lastindex;
};
#endif