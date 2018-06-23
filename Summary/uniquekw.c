#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "findpat.h"
#include "wordstats.h"
#include "createstring.h"
#include "copypastestring.h"

int main () {
	char *content = (char*)calloc(200000, sizeof(char));
	content = "for a game so focused on presenting a seamless interactive cinematic story, the most striking thing about detroit: become human is its exposed seams. like the world’s most slickly produced choose-your-own-adventure book, the latest david cage game lets you play with narrative conventions and mess with the inherent connective tissue of the story in some intriguing ways. but that underlying story ends up so fragmented, so poorly executed, and so clunkily written that it’s very difficult to appreciate the narrative playspace. the year is 2038, and the city of detroit is the center of a new manufacturing renaissance thanks to the creation of believable intelligent human-shaped androids. the world has been transformed by the existence of subservient machines that can do anything a human can do and more. people send their tireless automatons out for errands, ask them to cook and clean, and even take them along as glorified bag-holders on shopping runs. the military uses androids for combat operations, and space agencies use them for exploration. every facet of human life, from sports to entertainment to sex work, has been revolutionized by the availability of cheap, plentiful, hyper-intelligent superhuman servants. yet none of the humans presented in detroit seems at all happy to be finally free of menial manual labor. though androids have been allowed to integrate into seemingly every facet of detroit’s society, everyone is somehow also skeptical and distrustful of the ersatz humans that now dominate their ultra-modern lives. the game takes pains to show mass protests over the unemployment rate spiking past 35 percent, never really acknowledging that even unemployed slobs can apparently afford to buy a capable android to cater to their every whim. musicians desperately offer “music with soul” as somehow more authentic than the more popular brand of android-produced tunes. street vendors warn androids away for fear of scaring off customers, even though dozens of subservient androids wander every street. the police mistrust what seems to be the best, most reliable tool ever created for criminal investigations. for sure, there’s some level of existential dread inherent in the idea that we might be surpassed and/or made redundant by our own ai creations. but detroit doesn’t examine that interesting facet of human psychology very deeply. nor does it delve into the interesting social, economic, political, and interpersonal problems of a society no longer centered around productive human labor. monopoly android-maker cyberlife ends up being a bit player in the story despite being unquestionably the most successful corporation in history. instead, humanity is by and large presented as a sneering, vengeful, unsatisfied ruling class, exploiting and oppressing its creation just because it can. no one seems to think twice about bad-mouthing an android as a “fucking piece of plastic” to their face, confident the subservient machines will offer no resistance. anyone who has even a passing familiarity with science-fiction tropes knows what happens next. the once-docile androids start to rebel against their programming and their masters, going “deviant” by exercising a previously unknown free will that upends the existing social order. detroit’s near-instant moment of mass android awakening feels incredibly unearned compared to the complex explorations of artificial psychology in similar fiction (westworld, blade runner, etc, etc). how the resultant wave of self-awareness among these millions of machines plays out depends on the dialogue and action decisions you make through three cross-connecting android narratives. of these three plotlines, connor’s is by far the most interesting—and if you've seen preview footage of the game, you've seen this character attempt to negotiate a hostage situation. as a highly advanced android model helping the detroit police investigate crimes involving other androids, connor provides a perfect framing device for unraveling the mystery and consequences of rising bot independence. connor’s police work also forces you to be observant: finding clues can help provide more options to deal with everything from a hostage situation to an interrogation, while missing clues can cut off important options later in the game. despite being all metal and electronics, connor somehow shows the most humanity and growth of any detroit character. his frequent work with lt. hank anderson—a hard-boiled, alcoholic android-skeptic—shows a subtlety and humor that is almost entirely lacking from the rest of the game. small decisions on how to handle hank can lead him to become more hostile or more accepting of connor and all androids, each with significant repercussions for how the story plays out. all the while, connor is constantly fighting through his own potential instability, with your decisions determining his final fate. kara, by contrast, presents a much more personal story with fewer knock-on effects for the larger narrative. the domestic servant android is quickly forced to defy her programming and rescue a young child, alice, from her cartoonishly evil, abusive father. from there she has to learn to become a surrogate mother to alice as they struggle to survive in a cold and largely indifferent world. kara’s story seems over-designed to tug on the emotional heartstrings. while there are some touching smaller moments where this effort bears fruit—like crafting a personalized bedtime story for alice—for the most part the game is too nakedly emotionally manipulative to really be satisfying. kara’s scenes are full of swelling strings and mawkish sentimentality that seem to be begging you to feel something now. kara and alice’s story also leads up to a twist that is both heavily telegraphed and nearly impossible to accept when it finally happens. i won’t hint at what it is here, but suffice it to say that the reveal feels unearned and nonsensical in equal measure. finally, there’s markus, the jesus-like savior of android-kind who rises up from his slavery to lead his people to justice. as he uses seemingly mystical powers to awaken consciousness in his android brethren, markus’ choices determine whether the deviant androids employ passive demonstration or active aggression in their fight for freedom. you must login or create an account to comment. join the ars orbital transmission mailing list to get weekly updates delivered to your inbox.";
	
	char *ref = (char*)calloc(200000, sizeof(char));

	int start = 0;
	int end = 0;
	int length = strlen(content);
	int occ = 0;
	int lastindex = 0;
	char *tempword = (char*)calloc(200, sizeof(char));

	for (int i = 0; i < length; i++) {
		if (content[i] != ' ') {

		} else {

		end = i - 1;
		start = start;

		tempword = makestring(start, end, content);
		occ = findpattern(ref, tempword);

		if (occ == 0)
		{
			transferstring(tempword, ref, lastindex);
			lastindex = lastindex + strlen(tempword);
		}

		start = i + 1;
		}
	}
	ref[lastindex] = '\0';
	return 0;
};