#include <stdio.h>

short mehrfachvorkommen(int zahlen[][6], int wochen) {
	int i = 0;
	int j = 0;
	int paar = 0;
	for ( i = 0; i < wochen; i++ ) {
		for ( j = 0; j < 5; j++ ) {
			if ( zahlen[i][j+1] - zahlen[i][j] == 1 ) {
				printf("j: %d und j+1: %d\n", zahlen[i][j], zahlen[i][j+1] );
				paar++;
			}
		}
	}
	return paar;
}

int main() {
	int zahlen[][6] = {
		{1, 2, 5, 7, 29, 31},
		{32, 35, 37, 38, 42, 49 },
		{17, 22, 23, 24, 39, 41}
		};
	printf("%d", mehrfachvorkommen(zahlen, 3) );

	return 0;
}
