// Given 2 ints, a and b, output "Makes 10!"
// if one if them is 10 or if their sum is 10.
// Complete the following program:

#include <stdio.h>

int main(void) {
  	int a, b;

	scanf("%d %d", &a, &b);

	if (a == 10 || b == 10 || a + b == 10) {
		printf("Makes 10!\n");
	}

  return 0;
}
