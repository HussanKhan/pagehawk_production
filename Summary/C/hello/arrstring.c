#include <stdio.h>

int main() {
	char names[5][500];
	int i;
	int j;
	char first[100];
	char last[100];

	printf("Enter 5 Names\n");
	for (i = 0; i < 5; ++i) {
		scanf("%20[a-zA-z ]\n", names[i]);
	};

	printf("\nNames You Entered\n");
	printf("---------------------\n");
	for (i = 0; i < 5; ++i) {
	 	printf("  - %s\n", names[i]);
	};
	
	return 0;
}