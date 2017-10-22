//card test 4
//Test of Outpost card
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "rngs.h"

#define CARD_UNDER_TEST "OUTPOST"

//Set up game variables
int setup(){
	int i, j, m;
	int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
	int seed = 555;
	//int seed = (rand() % 20)+1;
	int numPlayers = 2;
	struct gameState Game, pre;
	int k[10] = {adventurer, smithy, embargo, village, minion, mine, cutpurse,
				sea_hag, outpost, great_hall};
}

void assert(int testResult, int expected,  char* resultString) {
  if(testTesult == expected) {
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
  
	setup();
  
	//initialize a new game
	initializeGame(numPlayers, k, seed, &Game);
	
	// add card under test
	G.hand[p][5]=outpost;
	G.handCount[p]++;
	
	memcpy(&pre, &Game, sizeof(struct gameState));
	cardEffect(smithy, choice1, choice2, choice3, &Game, 5, &bonus);

	return 0;
}