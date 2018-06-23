#include <stdio.h>
#include <string.h>
#include "findpat.h"
#include "wordfreq.h"

int main () {
	char *text = (char*)calloc(10000, sizeof(char));
	text = "ea and dice's reveal event for battlefield v concluded on wednesday with a whopper of a \"real-time\" gameplay trailer—and an apparent about-face from the developer's previous microtransaction strategies. the military shooter sequel will launch on xbox one, playstation 4, and windows pc on october 19, with pre-order and special-edition versions unlocking on october 16, while ea access members (only on xb1/pc) get an even earlier crack on october 11. as long rumored, the game will revolve around world war ii, and today's gameplay trailer, according to ea, is made entirely out of \"pre-alpha game-engine footage representative of game experience.\" the reveal video starts with a fast-moving cinematic sequence that follows a four-strong crew of british soldiers storming a home on a battleground. bullet holes puncture the house's walls and let in crepuscular rays of light while other elements of the house fall apart, especially once one soldier jumps through a window and looks back to see much of the structure crumble under the weight of advancing tanks. shortly after an advancing-tank, crashing-plane sequence, the trailer's perspective is that of a first-person shooter, and a giant axis-versus-allies battle interface appears while guns rattle and volumetric plumes of smoke and fire envelop the entire scene. time will tell whether this reveal video truly compares to the real gameplay coming to pcs and consoles this october. in the meantime, ea and dice revealed some harder, welcome news: bfv's core online gameplay—including modes, maps, weapons, and accessories—will all be included in the retail purchase price. players will not need to buy a season pass or mission packs to access any maps in the game. microtransactions will be limited to cosmetics, as confirmed by venturebeat, and players will pick through a \"company\" menu between battles to customize looks as they see fit. further readingstar wars: battlefront ii’s new update axes “pay-to-win” upgradesthe game's livestream event included a hard confirmation from dice senior producer andreas morell that no \"pay-to-win\" system will ever appear in bfv—meaning the game's players shouldn't expect to confront any battlefront ii-style currency system to access higher-level perks. we're still waiting to hear exactly how progression for new weapons and items will work, however, along with more info on the new, vaguely hinted-at \"grand operations\" mode—which sounds suspiciously like a 100-player \"battle royale\" mode. update, 7:15 p.m.: a huge pc gamer article sums up a ton of mechanical details about what to expect in bfv, including an important one: that grand operations is not, as incorrectly suggested earlier, a battle royale mode. instead, it will expand upon battlefield 1's multi-stage operations mode and split combat into multiple, epic \"days\" of battle. the game also says goodbye to fully regenerating health; now, if a soldier loses a significant amount of health in a life, he or she will only regain up to the nearest \"bar\" on a life meter. further readinganalysis: player interest in call of duty’s campaigns is crateringthe game will include \"fortifications\" as a buildable option in the middle of certain combat modes, though these will include pre-defined content like sandbags, tank stoppers, and trenches. and a serious reduction of per-spawn ammo means players will have to be more careful with ammo and rely on magazines from their fellow squadmates. plus, since the original report didn't make it clear: bfv will ship with a single-player mode, unlike its major fall-2018 competition call of duty: black ops 4. listing image by ea/dice ars technica's sam machkovech visits microsoft for a first-hand look at the company's new controller that focuses on accessibility.";
	char *word = (char*)calloc(10000, sizeof(char));
	// printf("\nOrg Text --- %s\n", text);
	// cleantext(text, word);
	// printf("\nStopTest --- %s\n", word);
	wordfreq(text, word);
	printf("\nTHE RESULT ---- %s\n", word);

	return 0;
}