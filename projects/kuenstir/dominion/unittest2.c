//unit test 2
//Test of card increment

#include "dominion.h"
#include "dominion_helpers.h"
#include <stdio.h>
#include <stdlib.h>
#include "rngs.h"

#define TEST_ID "Unit Test 2 : Hand Increment Test"

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

  struct gameState G;
  
  int kingdom[10] = {adventurer, smithy, embargo, village, minion, mine, cutpurse,
				sea_hag, outpost, great_hall};
  
  initializeGame(2, kingdom, 24, &G);
  
  G.whoseTurn = 1;
  G.coins = 500;
  G.handCount[1]++;
				
  testAssert(numHandCards(&G), 1, "Cards in hand was equal to 1");
  
  G.handCount[1]++;
				
  testAssert(numHandCards(&G), 2, "Cards in hand was equal to 2");
  
  G.handCount[1]++;
  
  testAssert(numHandCards(&G), 3, "Cards in hand was equal to 3");
				
  return 0;
}