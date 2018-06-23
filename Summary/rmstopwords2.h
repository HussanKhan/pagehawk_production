char * strippunc(char *content) {
	int i = 0;
	int trigger = 0;
	int length = strlen(content);
	int backscale = 0;
	int trigger = 0;
	for (i = 0; i < length + 1; i++) {
		if (content[i] == ' ') {
			end = i - 1;
			start = start;

			//Puts spaces in text where there is a stopword
			char *tempword = (char*)calloc(2000, sizeof(char));
			tempword = makestring(start, end, text);
			int occ = findpattern(stopwords, tempword);
			content[i - backscale] = content[i + 1];
			trigger = 1;
		} 

		if (trigger == 1)
			{
				content[i] = ' ';
				trigger = 0;
				++backscale;
			} else {
				content[i - backscale] = content[i];
			}	
	};
	// int length2 = strlen(dest);
	// dest[length2] = '\0';
	return content;
};