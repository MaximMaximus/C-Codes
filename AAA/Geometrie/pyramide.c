#include <stdio.h>
#include <math.h>

int main() {
	int i = 0;
	int j = 0;
	int x = 4;
	int star = 0;

	for(i = x; i >= 1; i--) {
		for(j = 1; j <= x - i; j++) {
			printf(" ");
		}
		while(star != (2*i - 1)) {
			printf("*");
			star++;
		}
		star = 0;
		printf("\n");
	} 
	
	return 0;
}
