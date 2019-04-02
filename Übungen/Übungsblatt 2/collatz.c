#include <stdio.h>

int main () {
	int n = 0;
	int i = 1;
	
	//printf("Bitte geben Sie eine Zahl groeser 1 ein: ");
	scanf("%d", &n);
	
	
	do {	
		if ( n > 1 ) {
			i++;
			if ( n % 2 == 1 ) {
				n = (3 * n) + 1;
			} else if ( n % 2 == 0 ) {
				n = n / 2;
			}
			// printf("Zahl %d: %d\n", i, n );
			
			if ( n == 1 ) {
				break;
			}
		}
	} while ( n > 1 );
	
	printf("%d", i);
	
	return 0;
}
