#include <stdio.h>

int main() {	

	int aepfel = 160;

	int fritz = 0;
	int hans = 0;

	int i = 0;
	int rest = aepfel;

	if ( aepfel % 8 == 0 ) {
		printf("Fritz: %3d | Hans: %3d | Rest: %3d\n", fritz, hans, aepfel );

		for ( i = 0; i < aepfel/8; i++ ) {
			rest -= 8;
			fritz += 5;
			hans += 3;

			printf("Fritz: %3d | Hans: %3d | Rest: %3d\n", fritz, hans, rest );
			//printf("i: %d\n", i);
		}

	} else {
		printf("Ende.\n");
	}

	return 0;
}
