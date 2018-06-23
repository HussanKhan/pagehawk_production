#ifndef STOPWORDCHECK
#define STOPWORDCHECK
#include <stdio.h>
#include <stdlib.h>
#include "findpatternrm.h"

int stopwordcheck (char *word) {
	char *stopwords = (char*)calloc(1000, sizeof(char));
	stopwords = "a about above also after again it’s its finally thing just against somehow all like am an and even every seems any ’s are as at be because been before being below between both but by could can will really did do does doing down during each few for from further had has have having he hed hell hes her here heres hers herself him himself his how hows i id ill im ive if in into is it its its itself lets me more most my myself nor of on once only or other ought our ours ourselves out over own same she shed shell shes should so some such than that thats the their theirs them themselves then there theres these they theyd theyll theyre theyve this those through to too under until up very was we wed well were weve were what whats when whens where wheres which while who whos whom why whys with would you youd youll youre youve your yours yourself yourselves";

	if (findpatternrm(stopwords, word) != 0) {
		return 1;
	} else {
		return 0;
	}
};
#endif