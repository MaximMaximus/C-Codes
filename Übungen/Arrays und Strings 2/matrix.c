#include <stdio.h>
#include <stdlib.h>

int **eingabe(int elemente) {
	int **matrix;
	int i = 0;
	int j = 0;
	matrix = malloc(elemente * sizeof(int*));
	for( i = 0; i < elemente; i++ ) {
		matrix[i] = malloc(elemente * sizeof(int*));
	}
	for ( i = 0; i < elemente; i++ ) {
		for ( j = 0; j < elemente; j++ ) {
			printf("%d.%d Element eingeben: \n", i, j);
			scanf(" %d", &matrix[i][j]);
		}
	}
	return matrix;
}

void diagonale(int elemente) {
	int **matrix = eingabe(elemente);

	int i = 0;
	int j = 0;

	for ( i = 0; i < elemente; i++ ) {
		for ( j = 0; j < elemente; j++ ) {
		printf("%d.%d: %d\n", i, j, matrix[i][j]);
		}
	}

	printf("///MATRIX///\n");
	for ( i = 0; i < elemente; i++ ) {
		for ( j = 0; j < elemente; j++ ) {
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}
	
	int z;
	for(z=0; z<2*elemente-1; z++) {
		int spalte = z<elemente?0:z-elemente+1;
		int zeile = z<elemente?z:elemente-1;
		//printf("spalte: %d zeile: %d\n", spalte, zeile);
		while(zeile>=0 && spalte<elemente) {
			printf("%d z: %d\n", matrix[zeile][spalte], z);
			zeile--;
			spalte++;
		}
	}

	free(matrix);
}

int main() {
	int elemente;
	printf("Geben Sie die Anzahl der Elemente ein(Max 10): \n");
	scanf(" %d", &elemente);

	if ( elemente > 10 ) {
		while(elemente > 10) {
			printf("Zu viele Elemente!\nBitte neu eingeben: \n");
			scanf(" %d", &elemente);
		}
	}

	diagonale(elemente);

	return 0;
}
