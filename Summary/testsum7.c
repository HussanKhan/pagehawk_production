#include <stdio.h>
#include <stdlib.h>
#include "findpat.h"

int main() {
	char *text = (char*)calloc(10000, sizeof(char));
	text = "Nine months ago, Jaguar Land Rover announced it was planning to phase out internal combustion engines, along with offering electrified versions of all its models by 2020. But the I-Pace—its first battery electric vehicle—predates all of that. Apart from the Chevrolet Bolt EV, it's the only EV on sale that can compete with Tesla on range thanks to a whopping 90kWh battery pack. And unlike the Bolt (which remains a rather no-frills affair), the I-Pace is most assuredly a luxury car. Its exterior and interior seem leagues ahead of anything the Internet's favorite car company has given us so far. Like any battery EV, this remains a vehicle that's not right for everyone. If your needs include being able to drive across the country in a single day in as short a time as possible, you might want to look elsewhere. Ditto if you need to carry five or six passengers. And the I-Pace is not particularly cheap—prices start at $69,500 in the US before any federal or local incentives are taken into account. But it's better looking and better made than any other BEV on sale today, with a good warranty and plenty of gadgets. With 295kW (394hp) and 694Nm (512ft-lbs), it also has plenty of performance and doesn't take up that much space. Its footprint is about the same as Jaguar's petite E-Pace SUV even though there's tons of room regardless of whether you're sitting in the front or back.";
	


	printf("\n%d\n", findpattern(text, "EV"));
	return 0;
}