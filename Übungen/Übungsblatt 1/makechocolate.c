/*We want to make a package of goal kilos of chocolate. We have a various number of small bars (1 kilo each) and big bars (5 kilos each) available on stock. Return the number of small bars to use, assuming we always use big bars before small bars. 

The result -1 means it can't be done. 

Example 1:
Assume you call your program with these inputs: 10 2 17
(i.e. you have 2 x 5 kg bars, 10 x 1 kg bars, and you need to produce 17 kg of chocolate)
2 x 5 kg are used, 7 kg are remaining and are on stock --> 7 is the result to be printed

Example 2:
Assume you call your program with these inputs: 3 2 17
(i.e. you have 2 x 5 kg bars, 3 x 1 kg bars, and you need to produce 17 kg of chocolate)
2 x 5 kg are used, 7 kg are remaining but you have only 3 on stock --> -1 is the result to be printed (fault, can't be done.)

Complete the following program code. For your final submission, remove the comment that tells you where to add your code.*/

#include <stdio.h>

int main(void) {
  /* Number of 1kg bars available on stock. */
  int small_bars;

  /* Number of 5kg bars available on stock. */
  int big_bars;

  /* Make a package of goal kilos of chocolate. */
  int goal;

  /* Number of small bars used, -1 means it cannot be done. */
  int used_small_bars = -1;

  scanf("%d %d %d", &small_bars, &big_bars, &goal);

if (big_bars == goal && goal % 5 == 0) {
    small_bars = 0;
    printf("%i\n", small_bars);
  } else if (small_bars >= goal && goal <= 5) {
    small_bars = goal;
    printf("%i\n", small_bars);
  } else if ((small_bars + 5 * big_bars) >= goal) {
    small_bars = goal - (5 * big_bars);
    printf("%i\n", small_bars);
  } else {
    printf("%d\n", used_small_bars);
  }


  return 0;
}
