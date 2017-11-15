//random test card 1
//Random Test of Outpost card

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "rngs.h"

#define CARD_UNDER_TEST "ADVENTURER"

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
	
		//check how much treasure player has
		int startTreasure = (rand() % 20)+1;
		startTreasure += G.supplyCount[copper];
		startTreasure += G.supplyCount[silver];
		startTreasure += G.supplyCount[gold];
		
		// add card under test
		G.hand[1][5]=adventurer;
	
		//play card
		memcpy(&otherG, &G, sizeof(struct gameState));
		cardEffect(adventurer, choice1, choice2, choice3, &G, 5, &bonus);
		
		//check how much treasure player has
		int endTreasure = startTreasure;
		endTreasure += G.supplyCount[copper];
		endTreasure += G.supplyCount[silver];
		endTreasure += G.supplyCount[gold];
		
		if(testAssert(endTreasure - startTreasure, 2, "Adventurer card played as expected\n")){
		}
		
	}
	
	return 0;
}