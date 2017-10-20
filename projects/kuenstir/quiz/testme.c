//Kuenstir

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include <math.h>

//Returns a random char (as int)
char inputChar()
{
    char randomchar = 32 + (floor(rand() % 95));
    return randomchar;
}

//returns a random 10 character string
char *inputString()
{
	static char string[11];
    int i;

    //There is a 1 in 1000 chance we may send the reset line instead of a random string each iteration.
	if(floor(rand() % 1000)){
        for(i = 0; i < sizeof(string)-1; i++)
            {
                string[i] = inputChar();
            }
	}
    else{
        //overwrite first 6 characters with reset string
        string[0] = 'r';
        string[1] = 'e';
        string[2] = 's';
        string[3] = 'e';
        string[4] = 't';
        string[5] = '\0';
    }

    //null terminate the string
    i = sizeof(string)-1;
    string[i] = '\0';

	return string;
}

void testme()
{
  int tcCount = 0;
  char *s;
  char c;
  int state = 0;
  while (1)
  {
    tcCount++;
    c = inputChar();
    s = inputString();
    printf("Iteration %d: c = %c, s = %s, state = %d\n", tcCount, c, s, state);

    if (c == '[' && state == 0) state = 1;
    if (c == '(' && state == 1) state = 2;
    if (c == '{' && state == 2) state = 3;
    if (c == ' '&& state == 3)  state = 4;
    if (c == 'a' && state == 4) state = 5;
    if (c == 'x' && state == 5) state = 6;
    if (c == '}' && state == 6) state = 7;
    if (c == ')' && state == 7) state = 8;
    if (c == ']' && state == 8) state = 9;
    if (s[0] == 'r' && s[1] == 'e'
       && s[2] == 's' && s[3] == 'e'
       && s[4] == 't' && s[5] == '\0'
       && state == 9)
    {
      printf("error ");
      exit(200);
    }
  }
}


int main(int argc, char *argv[])
{
    srand(time(NULL));
    testme();
    return 0;
}
