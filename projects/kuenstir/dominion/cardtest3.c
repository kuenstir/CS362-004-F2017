//card test 3
//Test of Sea_Hag Card

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "rngs.h"

#define CARD_UNDER_TEST "SEA HAG"

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
	
	cardEffect(card, choice1, choice2, choice3, &G, handPos, &bonus);
  
	G.whoseTurn = 1;

	// add card under test
	G.hand[1][5]=sea_hag;
	G.handCount[1] += 5;
	int storeHandCount = G.handCount[1];
	
	memcpy(&otherG, &G, sizeof(struct gameState));
	cardEffect(sea_hag, choice1, choice2, choice3, &G, 5, &bonus);
	
	if(testAssert(G.handCount[1], storeHandCount, "Sea Hag did not force current player to discard")){
	}
	
	// add card under test
	G.whoseTurn = 1;
	G.hand[1][5]=sea_hag;
	G.handCount[1] += 5;
	storeHandCount = G.handCount[1];
	
	memcpy(&otherG, &G, sizeof(struct gameState));
	cardEffect(sea_hag, choice1, choice2, choice3, &G, 5, &bonus);
	
	if(testAssert(G.handCount[1], storeHandCount, "Sea Hag did not force current player to discard")){
	}
	
	// add card under test
	G.whoseTurn = 1;
	G.hand[1][5]=sea_hag;
	G.handCount[1] += 5;
	storeHandCount = G.handCount[1];
	
	memcpy(&otherG, &G, sizeof(struct gameState));
	cardEffect(sea_hag, choice1, choice2, choice3, &G, 5, &bonus);
	
	if(testAssert(G.handCount[1], storeHandCount, "Sea Hag did not force current player to discard")){
	}
	
	return 0;
}