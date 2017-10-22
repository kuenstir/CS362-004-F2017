//card test 1
//Test of Smithy Card

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "rngs.h"

#define CARD_UNDER_TEST "SMITHY"

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

	int* bonus = &(G.coins);
	
	cardEffect(card, choice1, choice2, choice3, &G, handPos, bonus);
  
	G.whoseTurn = 1;

	// add card under test
	G.hand[1][5]=smithy;
	G.handCount[1]++;
	int storeHandCount = G.handCount[1];
	
	memcpy(&otherG, &G, sizeof(struct gameState));
	cardEffect(smithy, choice1, choice2, choice3, &G, 5, bonus);
	
	if(testAssert(G.handCount[1], storeHandCount + 3, "Smithy added 3 cards to player hand")){
		printf("\n\tActual: %d\n\n", storeHandCount - G.handCount[1] + 3);
	}
		
	// add card under test
	G.hand[1][5]=smithy;
	G.handCount[1]++;
	storeHandCount = G.handCount[1];
	
	memcpy(&otherG, &G, sizeof(struct gameState));
	cardEffect(smithy, choice1, choice2, choice3, &G, 5, bonus);
	
	if(testAssert(G.handCount[1], storeHandCount + 3, "Smithy added 3 cards to player hand")){
		printf("\n\tActual: %d\n\n", storeHandCount - G.handCount[1] + 3);
	}
		
	// add card under test
	G.hand[1][5]=smithy;
	G.handCount[1]++;
	storeHandCount = G.handCount[1];
	
	memcpy(&otherG, &G, sizeof(struct gameState));
	cardEffect(smithy, choice1, choice2, choice3, &G, 5, bonus);
	
	if(testAssert(G.handCount[1], storeHandCount + 3, "Smithy added 3 cards to player hand")){
		printf("\n\tActual: %d\n\n", storeHandCount - G.handCount[1] + 3);
	}
	return 0;
}