#include <stdio.h>
#include <stdlib.h>

int * quicksort(int *arr, int n, int length) {
	if (n > 1) {
	int i;
	int incr = (length-n);
	int piv = (length-n);
	for (i = 0; i < n; i++)
	{
		if (arr[piv] < arr[i + incr])
		{
			int temp = arr[piv];
			arr[piv] = arr[i + incr];
			arr[i + incr] = temp;
		} 
	}

	quicksort(arr, (n-1), length);
	} else {
		return arr;
	}
}


int main () {
	int arr[] = {4, 6, 7, 8, 9, 3, 1, 2, 78, 87, 90};

	int *tarr = quicksort(arr, 10, 10);
	
	for (int i = 0; i < 10; i++)
	{
		printf("\n%d\n", arr[i]);
	}
	return 0;
}