//unit test 1
//Test of shuffle

#include "dominion.h"
#include "dominion_helpers.h"
#include <stdio.h>
#include <stdlib.h>
#include "rngs.h"

#define TEST_ID "Unit Test 1 : Shuffle Test"

int testAssert(int result, int expected,  char* resultString) {
  if(result != expected) {
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
  
  initializeGame(2, kingdom, 27, &G);
  
  shuffle(1, &G);
  int handCard1 = G.deck[1][1];
  shuffle(1, &G);
  int handCard2 = G.deck[1][1];
				
  testAssert(handCard1, handCard2, "Cards in new order after shuffle");
				
  testAssert(handCard1, handCard2, "Cards in new order after shuffle");
  
  testAssert(handCard1, handCard2, "Cards in new order after shuffle");
				
  return 0;
}