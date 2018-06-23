#include <stdio.h>

// Allocate memory as you need it, very efficeint

// malloc, memory allocation 
// Allocated memory at runtime

int main () {
	// return address to *pnumber pointer, tell pointer where the memory is located
	int *pnumber = (int*)malloc(100);
					// malloc returns void pointer, so int* makes it into a int pointer

	// RELEASING MEMORY, MEMORY IS A VITAL RESOURCE, SO IF YOU'RE NOT USING IT, LET IT GO

	// Memory leak is when you allocate memory, but don't have refrence to release it
	// Commonly occurs is loop
	
	// Use free(pnumber) to free memory
	// pnumber = NULL;

	// calloc(75, sizeof(int)), init each memory spot by giving it a zero, malloc just has empty slots, calloc more secure, but slower 
	
	//|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
	//|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
	//|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
	//|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
	
	// Realloc lets you extend or reuse memory from malloc or calloc
	
	// 2 args, pointer, and how many bytes you want allocated 
	// realloc(pointer, newsize)
	return 0;
}
 