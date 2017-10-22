//unit test 3
//Test of 

#include "dominion.h"
#include "dominion_helpers.h"
#include <stdio.h>
#include <stdlib.h>
#include "rngs.h"

#define TEST_ID "Unit Test 3 : Draw Card Test"

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
	
  struct gameState g;
  int kingdom[10] = {adventurer, smithy, embargo, village, minion, mine, cutpurse,
				sea_hag, outpost, great_hall};
				
  initializeGame(2, kingdom, 345, g);
  
  g.handCount[1] = 5;
  drawCard (1, g);
 
  testAssert(g.handCount[1], 6, "player 1 handcount incremented by 1");
  
  drawCard (1, g);
  testAssert(g.handCount[1], 7, "player 1 handcount incremented by 1");
  
  drawCard (1, g);
  testAssert(g.handCount[1], 8, "player 1 handcount incremented by 1");

  return 0;
}