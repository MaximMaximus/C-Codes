 /*
 We are having a party with amounts of tea and candy.
 The following program determines the outcome of the party,
 whether it is bad, good, or great.
 A party is good (1) if both tea and candy are at least 5.
 However, if either tea or candy is at least double the amount of the other one,
 the party is great (2).
 However, in all cases, if either tea or candy is less than 5, the party is always bad (0).

Refactor the following program by extracting method how_successful.
This method contains the code to determine whether a tea party is successful.

Make sure you do not break the program!
The program must have the same behavior before and after refactoring.

For your final solution, remove the comments.

Hints:
Do not define function how_successful within the main function!
Advanced programmers: Do not use global variables. 
They are evil. Make sure each variable is defined within a function body.
*/

#include <stdio.h>

int how_successful(int drink, int food) {
  int fun = 0;

  if (drink >= 5)
  if (food >= 5) fun = 1;
  if (drink >= 2 * food) fun = 2;
  if (food >= 2 * drink) fun = 2;
  if (drink < 5) fun = 0;
  if (food < 5) fun = 0;
  return fun;
}

int main(void) {
  int tea;
  int candy;

  /* 0 = bad, 1 = good, 2 = great */
  int party = 0;

  scanf("%d %d", &tea, &candy);

  party = how_successful(tea, candy);

  /* Do not change anything below this line. */

  if (party == 0)
    printf("bad");
  else if (party == 1)
    printf("good");
  else
    printf("great");

  return 0;
}
