//random test card 2
//Random Test of Great Hall card

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "rngs.h"

#define CARD_UNDER_TEST "Great Hall"

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
	
		//Give player a random number of actions
		int actions = (rand() % 20)+1;
		G.numActions = actions;
		printf("actions: %d", actions);
		
		// add card under test
		G.hand[1][5]=great_hall;
	
		//play card
		memcpy(&otherG, &G, sizeof(struct gameState));
		cardEffect(great_hall, choice1, choice2, choice3, &G, 5, &bonus);
		
		//see if outpostplayed has incremented
		int endActions = G.numActions;
		printf("\tend actions: %d\n", endActions);
		
		if(testAssert(endActions - actions, 1, "Great Hall played and recorded as expected\n")){
		}
		
	}
	
	return 0;
}