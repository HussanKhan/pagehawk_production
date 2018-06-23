#ifndef QUICKSORT2
#define QUICKSORT2
#include <stdio.h>
#include <stdlib.h>

//Swaps two elements in index
void swap(int *arr, int i, int index) {
	int temp = arr[index];
	arr[index] = arr[i];
	arr[i] = temp;
}

// QUICKSORT CODE HERE
int * quicksort(int *arr, int l, int r) {
	int i;
	//only progress if array size not 1
	if ((r - l) > 1) {
		for (i = l; i < r; i++)
		{	
			//If value is less than far right pivot, swap with value at wall 
			if (arr[r] <= arr[i])
			{
				swap(arr, l, i);
				++l;
			}
		};

		//Places pivot at center
		swap(arr, r, (l));

		//lesser numbers
		quicksort(arr, 0, l-1);

		//greater numbers
		quicksort(arr, l, r);
		
	} else {
		return arr;
	}
	return 0;
};
#endif