long long int start = 0;
long long int end = 0;
char *tempw;
int append = 1;
for (int i = 0; i < strlen(text); i++) {
		if (text[i] != ' ') {

		} else {

			end = i - 1;
			start = start;
			
			if (end - start > 2) {
				tempw = makestring(start, end, text);
				if (size_of_uwords != 0) {
					for (s = 0; s < size_of_uwords; s++) {
						if (comparestr(*(uwords + s), tempw) != 0) {
						append = 0;
					} 
				}
			}

			if (append == 1) {
				*(uwords + size_of_uwords) = &*tempw;
				++size_of_uwords;
			} else {
				append = 1;
			}
		}
	}
	start = i + 1;
};