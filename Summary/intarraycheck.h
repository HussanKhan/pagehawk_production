#ifndef INTARRAYCHECK
#define INTARRAYCHECK
#include <stdio.h>
int arraycheck(int *arr, int n, int length) {
	int i;
	for (i = 0; i < length; ++i)
	{
		if (arr[i] == n) {
			return 1;
		}
	}
	return 0;
};
#endif

