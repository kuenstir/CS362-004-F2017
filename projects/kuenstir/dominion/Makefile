CFLAGS = -Wall -fpic -coverage -lm

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)
#To run playdom you need to entere: ./playdom <any integer number> like ./playdom 10*/
testDrawCard: testDrawCard.c dominion.o rngs.o
	gcc  -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

badTestDrawCard: badTestDrawCard.c dominion.o rngs.o
	gcc -o badTestDrawCard -g  badTestDrawCard.c dominion.o rngs.o $(CFLAGS)

testBuyCard: testDrawCard.c dominion.o rngs.o
	gcc -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

testAll: dominion.o testSuite.c
	gcc -o testSuite testSuite.c -g  dominion.o rngs.o $(CFLAGS)
	
result: runRandTests
	./randTest1 &> testresults.out
	./randTest2 >> testresults.out
	./advTest3 >> testresults.out

runRandTests: randTests
	./randTest1 
	./randTest2
	./advTest3

randTests:
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.o randomtestcard1.c rngs.o -o randTest1 -lm -g
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.o randomtestcard2.c rngs.o -o randTest2 -lm -g
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.o randomtestadventurer.c rngs.o -o advTest3 -lm -g

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

runtests: testDrawCard 
	./testDrawCard &> testresults.out
	gcov dominion.c >> testresults.out
	cat dominion.c.gcov >> testresults.out


player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all: playdom player testDrawCard testBuyCard badTestDrawCard

clean:
	rm -f *.o playdom.exe playdom player player.exe  *.gcov *.gcda *.gcno *.so *.out testDrawCard testDrawCard.exe
