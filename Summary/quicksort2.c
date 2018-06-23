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
	//only progress if array size not 1
	if ((r - l) > 1) {
		for (int i = l; i < r; i++)
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
}
#endif
int main () {
	int arr[] = {34,10,4,9,32,90,76,5,3,7,45,100, 232, 565};

	int *tarr = quicksort(arr, 0, 13);
	
	for (int i = 0; i < 14; i++)
	{
		printf("\n %d -- %d\n", i, arr[i]);
	}
	return 0;
}