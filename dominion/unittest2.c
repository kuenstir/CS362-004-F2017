//unit test 3
//Test of buy card increment

#include "dominion.h"
#include "dominion_helpers.h"
#include <stdio.h>
#include <stdlib.h>
#include "rngs.h"

#define TEST_ID "Unit Test 3 : Card Cost Test"

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
	
	printf("\n\n*** UNIT TEST - %s ***\n\n", TEST_ID);

  int i, deckCount, discardCount, handCount;

  struct gameState G;
  
  int kingdom[10] = {adventurer, smithy, embargo, village, minion, mine, cutpurse,
				sea_hag, outpost, great_hall};
  
  initializeGame(2, kingdom, 24, G);
  
  G.whoseTurn = 1;
  
  G.handCount = 6;
				
  testAssert(fullDeckCount(1, 1, G), 6, "Full Deck Count was equal to 6");
  
  G.handCount = 2;
				
  testAssert(fullDeckCount(1, 1, G), 6, "Full Deck Count was equal to 2");
  
  G.handCount = 9;
				
  testAssert(fullDeckCount(1, 1, G), 6, "Full Deck Count was equal to 9");
				
  
  return 0;
}