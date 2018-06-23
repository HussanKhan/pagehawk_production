#include <stdio.h>
#include <stdlib.h>
#include "summary2.h"
int main () {
	char *text = (char*)calloc(100000, sizeof(char));
	text = "Messages in iCloud has been in the works for a long time, and it has appeared and disappeared from various beta releases of Apple software. It was added in iOS 11.4 earlier this week, and now it's supported on Macs. The feature allows you to store communications you receive and send within the Messages app—plus associated file attachments—in iCloud to save space on your local device. It also means that changes like deleting messages are propagated across devices, and a new Mac that is logged into your iCloud account will immediately have access to your Messages history. 10.13.5 includes some security updates as well, which Apple has detailed on its support website. For example, the update addresses vulnerabilities in graphics drivers for Intel and AMD chips that allowed applications to read restricted memory, and it fixes a vulnerability in the Mail app that allowed attackers to access the contents of encrypted emails. The update follows 10.13.4, which among other things added official external GPU support and new privacy features—though we found that eGPU support still has a way to go. Apple is expected to announce the details of macOS 10.14, a more major release expected in September, at its Worldwide Developers Conference on June 4.";
	
	char *comp = (char*)calloc(100000, sizeof(char));
	summary2(text, comp);
	printf("\n%s\n", comp);
	return 0;
}