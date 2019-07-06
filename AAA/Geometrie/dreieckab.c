#include <stdio.h>

int main() {
	int i = 0;
	int j = 0;
	int hoehe;
	
	printf("Bitte Hoehe eingeben: \n");
	fflush(stdin);
	scanf(" %d", &hoehe);

	for(i = 1; i <= hoehe; i++) {
		for(j = 1; j <= hoehe; j++) {
			if(j <= i) printf("*");
		}
		printf("\n");
	}
	return 0;
}
