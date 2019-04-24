#include <stdio.h>

int is_evenly_space(int x, int y, int z) {

	short test = 0;

	int erg1 = 0;
	int erg2 = 0;
	int erg3 = 0;

	int speicher = 0;

	if ( x == y && y == z ) {
		test = 1;
	}

	while ( y < x || z < y) {

		if ( x > z ) {
			speicher = x;
			x = z;
			z = speicher;
			speicher = 0;
		}

		if ( x > y ) {
			speicher = x;
			x = y;
			y = speicher;
			speicher = 0;
		}

		if ( y > z ) {
			speicher = y;
			y = z;
			z = speicher;
			speicher = 0;
		}
	}	

	printf("x: %d y: %d z: %d\n", x, y, z);
	
	erg1 = z - y;

	erg2 = y - x;

	if ( erg1 == erg2 ) {
		test = 1;
	} else {
		test = 0;
	}

	return test;

}

int main () {

	int x = 4;
	int y = 6;
	int z = 3;

	if ( is_evenly_space(x, y, z) ) {
		printf("Wahr\n");
	} else {
		printf("Falsch\n");
	}

	return 0;
}