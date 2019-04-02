#include <stdio.h>

int main () {
	int n = 0;
	int i = 0;
	int j = 0;
	
	//printf("Geben Sie bitte einen Wert ein: ");
	scanf("%d", &n);
	
	if ( n > 2 ) {
		for ( i = 1; i <= n; i++ ) {
			if ( i == 1 || i == n ) {
				for ( j = 1; j <= n; j++ ) {
				  printf("*");
				}
			} else {
				  printf("%*s", n + 1 - i, "*");
			}
			printf("\n");
		}
	}	
	
	return 0;
}
