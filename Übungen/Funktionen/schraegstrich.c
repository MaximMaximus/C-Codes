#include <stdio.h>

void zeichne_von_links_oben(double z, double s) {

	int y = 0;
	int x = 0;
	double k = z/s;

	printf("k: %.2f\n", k);

	for ( y = 0; y <= z; y++ ) {
		for ( x = 0; x <= s; x++ ) {
			if ( y == (int)(k*x) ) printf("*");
			else printf("-");
		}
		

		printf("\n");
	}
}

void zeichne_von_links_unten(double z, double s) {

	int y = 0;
	int x = 0;
	double k = z/s;

	printf("k: %.2f\n", k);

	for ( y = 0; y <= z; y++ ) {
		for ( x = 0; x <= s; x++ ) {
			int berechnetesY = (int)(-k*x)+z;
			if ( y == berechnetesY ) printf("*");
			else printf("-");
		}
		
		printf("\n");
	}
}

int main() {

	zeichne_von_links_oben( 10, 30 );
	zeichne_von_links_unten( 10, 30 );
	return 0;
}
