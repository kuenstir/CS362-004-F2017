//card test 2
//Test of Sea_Hag Card

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "rngs.h"

#define CARD_UNDER_TEST "GREAT HALL"

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
	printf("\n\n*** CARDTEST - %s ***\n\n", CARD_UNDER_TEST);
  
	struct gameState G, otherG;
	
	int card, choice1, choice2, choice3, handPos;
	 int kingdom[10] = {adventurer, smithy, embargo, village, minion, mine, cutpurse,
				sea_hag, outpost, great_hall};
	int players = 2;
	int seed = 589;
  
	initializeGame(players, kingdom, seed, &G);

	int bonus = 0;
  
	G.whoseTurn = 1;

	// add card under test
	G.hand[1][5]=great_hall;
	int storenumActions = G.numActions;
	
	memcpy(&otherG, &G, sizeof(struct gameState));
	cardEffect(great_hall, choice1, choice2, choice3, &G, 5, &bonus);
	
	if(testAssert(G.numActions, storenumActions + 1, "Great Hall Incremented the Player actions")){
	}
	
	// add card under test
	G.hand[1][5]=great_hall;
	storenumActions = G.numActions;
	
	memcpy(&otherG, &G, sizeof(struct gameState));
	cardEffect(great_hall, choice1, choice2, choice3, &G, 5, &bonus);
	
	if(testAssert(G.numActions, storenumActions + 1, "Great Hall Incremented the Player actions")){
	}
	
	// add card under test
	G.hand[1][5]=great_hall;
	storenumActions = G.numActions;
	
	memcpy(&otherG, &G, sizeof(struct gameState));
	cardEffect(great_hall, choice1, choice2, choice3, &G, 5, &bonus);
	
	if(testAssert(G.numActions, storenumActions + 1, "Great Hall Incremented the Player actions")){
	}
	
	return 0;
}