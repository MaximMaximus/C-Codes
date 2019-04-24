#include <stdio.h>

int friend(int zahl1, int zahl2) {

	short friends = 0;

	int summe1 = 0;
	int summe2 = 0;

	int i = 0;
	int j = 0;


	printf("zahl1: %d\n", zahl1);
	printf("zahl2: %d\n", zahl2);

	for ( i = 1; i < zahl1; i++ ) {
		if ( zahl1 % i == 1 ) {
			continue;
		}
		if ( zahl1 % i == 0 ) {
			//printf("I: %d\n",i);
			summe1 += i;
		}
	}

	for ( j = 1; j < zahl2; j++ ) {
		if ( zahl2 % j == 1 ) {
			continue;
		}
		if ( zahl2 % j == 0 ) {
			summe2 += j;
		}
	}

	printf("Summe1: %d\nSumme2: %d\n", summe1, summe2);
	if ( zahl2 == summe1 && zahl1 == summe2 ) {
		friends = 1;
	} else {
		friends = 0;
	}

	return friends;
}

int main() {

	int wert1 = 220;
	int wert2 = 284;

	if ( friend(wert1, wert2) ) {
		printf("Friends!\n");
	} else {
		printf("Strangers!\n");
	}

	return 0;
}
