//unit test 4
//Test of gameState variables

#include "dominion.h"
#include "dominion_helpers.h"
#include <stdio.h>
#include <stdlib.h>
#include "rngs.h"

#define TEST_ID "Unit Test 4: Gamestate Variables"

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
  
  g.numPlayers = 2;
  testAssert(g.numPlayers, 2, "numPlayers value set to 2");
  
  g.whoseTurn = 1;
  testAssert(g.whoseTurn, 1, "whoseTurn value set to player 1");

  return 0;
}