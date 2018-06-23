#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
	char *message = (char*)calloc(1000, sizeof(char));
	message = "I really enjoy eating cheese and llamas are cool";
	char *pat = (char*)calloc(1000, sizeof(char));
	pat = "cheese";

	int i;
	int value = 0;
	int lentest = 0;
	int messagelen = strlen(message);
	int patlen = strlen(pat);
	for (i = 0; i < messagelen; i++) {
		if (message[i] == pat[0]) {
			while (message[i + lentest] == pat[0 + lentest]) {
				lentest = lentest + 1;
			}
			if (lentest == patlen) {
				value = value + 1;
			}
		}
		lentest = 0;
	}
	printf("\n%d\n", value);
}