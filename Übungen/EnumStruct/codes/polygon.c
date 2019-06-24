#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef enum { false, true } Boolen;

typedef struct {
	char *name;
	double *coord;
} Point;

double abstand(Point p0, Point p1, int dim) {
	int i = 0;
	double summe = 0;
	for ( i = 0; i < dim; i++ ) {
		summe += pow(p1.coord[i] - p0.coord[i], 2);
	}
	return sqrt(summe);
}

double kettenlaenge(Point *punkte[], int anzahl, int dim) {
	int i = 0;
	double summe = 0;
	for ( i = 0; i < anzahl - 1; i++ ) {
		summe += abstand(*punkte[i], *punkte[i+1], dim);
	}
	return summe;
}

int numLenght(int num) {
	int i = 1;
	if ( num < 10 ) return 1;
	while(num) {
		i++;
		num / 10;
	}
	return i;
}


int main() {
	Boolen eingabe = true;
	int punkte = 0;
	int dimension = 0;

	
	while(eingabe) {
		printf("Bitte geben Sie die Anzahl der Punkte ein: \n");
		scanf(" %d", &punkte);
		if ( punkte < 2 ) {
			printf("Zur Berechnung werden mindestens zwei Punkte benoetigt.\n");
			printf("Bitte erneut eingeben.\n");
		} else {
			eingabe = false;
		}
	}

	eingabe = true;
	
	while(eingabe) {
		printf("Bitte geben Sie die Anzahl der Dimensionen ein: \n");
		scanf(" %d", &dimension);
		if ( dimension < 2 ) {
			printf("Zur Berechnung werden mindestens zwei Dimensionen benoetigt.\n");
			printf("Bitte erneut eingeben.\n");
		} else {
			eingabe = false;
		}
	}

	Point *array[punkte];
	int i = 0;
	int j = 0;
	char *bez;
	for ( i = 0; i < punkte; i++ ) {
		array[i] = (Point*)malloc(sizeof(Point));
		bez = malloc(numLenght(i)+1);
		sprintf(bez, "%d", i);
		array[i]->name = malloc(numLenght(i)+2);
		strcpy(array[i]->name, "p");
		strcat(array[i]->name, bez);
		array[i]->coord = malloc(dimension * sizeof(double));

		printf("Bitte geben Sie die %d Werte fuer Punkt %s ein: \n", dimension, array[i]->name);
		for ( j = 0; j < dimension; j++ ) {
			printf("%s - %d: ", array[i]->name, j+1);
			scanf(" %lf", &array[i]->coord[j]);
		}
	}

	printf("\nGesamtdistanz: %.2lf\n", kettenlaenge(array, punkte, dimension));
	for(i = 0; i < punkte; i++ ) {
		for (j = 0; j < dimension; j++ ) {
			printf("%s - %.2lf\n", array[i]->name, array[i]->coord[j]);
		}
	}
	return 0;
}
