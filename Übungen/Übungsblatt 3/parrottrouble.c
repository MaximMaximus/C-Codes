 /*
 An exercise from Codingbat:

We have a loud talking parrot. 
The "hour" parameter is the current hour time in the range 0..23. 
We (and our parrot) are in trouble if the parrot is talking and the hour is before 7 or after 20.

The function parrot_trouble returns 1 if we are in trouble.

Complete the following code:
*/

#include <stdio.h>

/*
  Returns 1 if we are in trouble, and 0 otherwise.
  If talking == 1, the parrot is talking, otherwise it is silent.
  The hour is the current hour time in range 0..23. 
*/
int parrot_trouble(int talking, int hour) {
  if ( hour < 7 || hour > 20 ) {
    if ( talking == 1 ) {
      return 1;
    }
  }
  return 0;
}

int main(void) {
  int input_talking;
  int input_hour;

  scanf("%d %d", &input_talking, &input_hour);

  if (parrot_trouble(input_talking, input_hour))
    printf("Oh no, parrot in trouble!");
  else
    printf("Everything's fine.");

  return 0;
}
