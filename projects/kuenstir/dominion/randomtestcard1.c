//random test card 1
//Random Test of Outpost card

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "rngs.h"

#define CARD_UNDER_TEST "OUTPOST"

int testAssert(int result, int expected,  char* resultString) {
  if(result == expected) {
    printf("PASS: %s\n", resultString);
	return 0;
  } 
  else {
    printf("FAIL: %s\n", resultString);
	return 1;
  }
}


int main() {
	printf("\n\n*** RANDOM TEST - %s ***\n\n", CARD_UNDER_TEST);
  
	struct gameState G, otherG;
	
	int card, choice1, choice2, choice3, handPos;
	int kingdom[10] = {adventurer, smithy, embargo, village, minion, mine, cutpurse,
				sea_hag, outpost, great_hall};
	int players = 2;
	int seed = (rand() % 999)+1;
  
	initializeGame(players, kingdom, seed, &G);

	int bonus = 0;
  
	G.whoseTurn = 1;
	
	//Loop
	int i;
	for(i = 0; i < 20; i++){
	
		//start with random number of prior plays, then check how many times outpost has been played
		int plays = (rand() % 20)+1;
		G.outpostPlayed = plays;
		printf("plays: %d", plays);
		
		// add card under test
		G.hand[1][5]=outpost;
	
		//play card
		memcpy(&otherG, &G, sizeof(struct gameState));
		cardEffect(outpost, choice1, choice2, choice3, &G, 5, &bonus);
		
		//see if outpostplayed has incremented
		int endplays = G.outpostPlayed;
		printf("\tend plays: %d\n", endplays);
		
		if(testAssert(endplays - plays, 1, "Outpost played and recorded as expected\n")){
		}
		
	}
	
	return 0;
}