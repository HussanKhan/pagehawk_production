#include <stdio.h>
#include <string.h>

int lenfind(char stuff[]) {
	int length = 0;
	int i;

	for (i = 0; stuff[i] != '\0'; ++i) {
		length = length + 1;
	}
	return length;
}

int main() {
	int i;
	//Find character in string
	char prac[] = "This is a practice string";
	char ch = 'p';
	// create pointer, stores address for char in string
	// points to index location
	char *gotem = NULL;
	// Finds charcter then assigns everything after
	// like this prac[random:]
	gotem = strchr(prac, ch);

	printf("\n%s\n", gotem);

	// Now finding a string
	char prac2[] = "C is a pretty cool language";
	char word[] = "pretty";
	char *found = NULL;
	// Finds string then assigns everything after
	// like this prac2[random:]
	found = strstr(prac2, word);

	printf("%s\n", found);

	// Tokenizing string

	char prac3[] = "Halo 3 is a 2007 first-person shooter video game developed by Bungie for the Xbox 360 console. The third installment in the Halo franchise, the game concludes the story arc begun in 2001's Halo: Combat Evolved and continued in 2004's Halo 2";

	// Select delimiter, what to seperate by
	const char de[] = " ";
	char *token;
	int length;
	// to continue on same string, feed null
	// token keeps pointing to diff location
	// YOU CAN PRINT STRING WITH IT
	length = lenfind(prac3);
	printf("\n");
	// intilize the string
	token = strtok(prac3, de);
	for (i = 0; token != NULL; ++i) {
		printf("%s ", token);
		token = strtok(NULL, de);	
	};
	printf("\n");
	
	// printf("%s", prac3);

	return 0;
}
