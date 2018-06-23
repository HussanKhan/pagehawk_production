#ifndef INTARRAYCHECK
#define INTARRAYCHECK
#include <stdio.h>
int arraycheck(int *arr, int value, int length) {
	int value = 0;
	for (int i = 0; i < length; ++i)
	{
		if (arr[i] == value) {
			++value;
		}
	}
	return value;
};
#endif

