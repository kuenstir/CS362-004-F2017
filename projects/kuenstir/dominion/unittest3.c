//unit test 3
//Test of max card cost

#include "dominion.h"
#include "dominion_helpers.h"
#include <stdio.h>
#include <stdlib.h>
#include "rngs.h"

#define TEST_ID "Unit Test 3 : Card Cost Test"

int testAssert(int result, int expected,  char* resultString) {
  if(result <= expected) {
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
	
  int i;
  int kingdom[10] = {adventurer, smithy, embargo, village, minion, mine, cutpurse,
				sea_hag, outpost, great_hall};
				
  for (i = 0; i < sizeof(kingdom)-1; i++){
	  testAssert(getCost(kingdom[i]), getCost(province), "selected card is not more expensive than province card");
  }
  
  return 0;
}