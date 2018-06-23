#include <stdio.h>
#include <string.h>

char * strippunc(char *content, char *dest) {
	int i;
	int length = strlen(content);
	for (i = 0; length; i++) {
		if (content[i] == '.' || content[i] == ',' || content[i] == '"' || content[i] == ';' || content[i] == ':') {
			dest[i] = '';
		} else {
			dest[i] = content[i];
		}
	}
	dest[length + 1] = '\0';
}