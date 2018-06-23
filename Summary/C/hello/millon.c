#include <stdio.h>

int main() {
	char names[5][256];
	int i;
	int j;
	printf("Enter 5 Names\n");
	for (i = 0; i < 5; ++i) {
		scanf("%s>\n", names[i]);
	};

	for (i = 0; i < 5; ++i) {
	 printf("%s\n", names[i]);
	}
	
	return 0;
}