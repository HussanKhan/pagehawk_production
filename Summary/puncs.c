#include <stdio.h>
#include <stdlib.h>
#include "strippunc.h"
#include "rmstopwords.h"

int main () {
	char *text = (char*)calloc(1000, sizeof(char));
	char *dest = (char*)calloc(1000, sizeof(char));
	char *clean = (char*)calloc(1000, sizeof(char));
	text = "Hello world, or what's your name my a guy";
	strippunc(text, dest);
	cleantext(dest, clean);
	return 0;
}