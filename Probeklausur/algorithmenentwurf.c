#include <stdio.h>

double kurs_durchschnitt(double *array, int werte) {
	int i = 0;
	int j = 0;
	double summe;
	for(i = 0; i < werte; i++) {
		summe += array[i];
	}
	return summe/werte;
}

void zeichnen(double *array, int werte) {
	int i = 0;
	int j = 0;
	double max_hoehe = 20;
	double max_wert = 0;
	int angezeigte_stelle[werte];
	
	// höchster Wert
	for( i = 0; i < werte; i++ ) {
		for( j = 0; j < werte; j++ ) {
			if( array[j] < array[j+1] ) {
				max_wert = array[j+1];
			}
		}
	}
	//printf("max wert %f\n", max_wert);

	for( i = 0; i < werte; i++ ) {
		angezeigte_stelle[i] = max_hoehe+1 - ((max_hoehe+1) / max_wert) * array[i];
		//printf("i %d wert %d\n", i, angezeigte_stelle[i]);
	}

	for( i = 0; i <= max_hoehe+1; i++) {
		if(i < max_hoehe) printf("%2d| ",20-i);
		if(i == max_hoehe) printf("XX+-");
		if(i == max_hoehe+1) printf("    ");
		for( j = 0; j < werte; j++ ) {
			if( i >= angezeigte_stelle[j] && i < max_hoehe ) printf("##     ");
			else if( i < angezeigte_stelle[j] && i < max_hoehe ) printf("%*s", 7, "");
			if(i == max_hoehe && j > 0) printf("+------");
			if(i == max_hoehe+1) printf("%-5g  ", array[j]);
		}
		printf("\n");
	}
}

int main() {

	double k[] = { 120., 150., 80., 14., 110., 65., 99., 180., 140., 55. };
	zeichnen (k, 10);
	printf("Durchschnittswert: %g\n", kurs_durchschnitt(k, 10));
	
	return 0;
}
