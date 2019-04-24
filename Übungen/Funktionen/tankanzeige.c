#include <stdio.h>

#define TANK_LITER 65
#define TANK_ANZEIGE_STELLEN 20

void tankanzeige_horizontal_1(double liter) {

	double tank_liter = TANK_LITER;
	double tank_anzeige = TANK_ANZEIGE_STELLEN;

	double getankte_stellen = (tank_anzeige/tank_liter) * liter;

	printf("Tankfuellung: %.2f%%\n", 100 / TANK_ANZEIGE_STELLEN * getankte_stellen);

	int i = 0;
	for ( i = 1; i <= getankte_stellen; i++) {
		printf("*");
	}
	printf(" %.2f L\n", liter);
}

void tankanzeige_horizontal_2(double liter) {

	double tank_liter = TANK_LITER;
	double tank_anzeige = TANK_ANZEIGE_STELLEN;

	double getankte_stellen = (tank_anzeige/tank_liter)  * liter;

	printf("Tankfuellung: %.2f%%\n", 100 / TANK_ANZEIGE_STELLEN * getankte_stellen);

	int i = 0;
	for ( i = 1; i <= TANK_ANZEIGE_STELLEN; i++) {
		if ( i <= getankte_stellen ) printf("*");
		else printf("-");
	}
	printf(" %.2f L\n", liter);
}

void tankanzeige_horizontal_3(double liter) {

	double tank_liter = TANK_LITER;
	double tank_anzeige = TANK_ANZEIGE_STELLEN;

	double getankte_stellen = (tank_anzeige/tank_liter)  * liter;

	printf("Tankfuellung: %.2f%%\n", 100 / TANK_ANZEIGE_STELLEN * getankte_stellen);

	int i = 0;
	int j = 0;

	for ( i = 0; i < 3; i++ ) {
		for ( j = 0; j <= TANK_ANZEIGE_STELLEN+1; j++) {
			if ( i == 0 || i == 2) 
				if ( j == 0 || j == TANK_ANZEIGE_STELLEN+1) printf("+");
				else printf("-");
			if ( i == 1 ) 
				if ( j == 0 || j == TANK_ANZEIGE_STELLEN+1) printf("|");
				else if ( j <= getankte_stellen ) printf("*");
				else printf(" ");
		}
		if ( i == 1 ) printf(" %.2f L", liter);
		printf("\n");
	}
}

void tankanzeige_vertikal_1(double liter) {

	double tank_liter = TANK_LITER;
	double tank_anzeige = TANK_ANZEIGE_STELLEN;

	double getankte_stellen = (tank_anzeige/tank_liter)  * liter;

	printf("Tankfuellung: %.2f%%\n", 100 / TANK_ANZEIGE_STELLEN * getankte_stellen);

	int i = 0;

	for ( i = TANK_ANZEIGE_STELLEN; i > 0; i-- ) {
		if ( i <= getankte_stellen ) printf("*\n");
			else printf("-\n");
	}
	printf("%.2f L\n", liter);
}

void tankanzeige_vertikal_2(double liter) {

	double tank_liter = TANK_LITER;
	double tank_anzeige = TANK_ANZEIGE_STELLEN;

	double getankte_stellen = (tank_anzeige/tank_liter)  * liter;
	int tabellen_liter = getankte_stellen;

	printf("Tankfuellung: %.2f%%\n", 100 / TANK_ANZEIGE_STELLEN * getankte_stellen);

	int i = 0;
	int j = 0;
	int spalten = 5;

	for ( i = TANK_ANZEIGE_STELLEN + 1; i >= 0; i-- ) {
		for ( j = 1; j <= spalten; j++ ) {
			if ( i == TANK_ANZEIGE_STELLEN + 1 || i == 0 )
				if ( j == 1 || j == spalten ) printf("+");
				else printf("-");
			else if ( i < TANK_ANZEIGE_STELLEN + 1 || i > 0 )
					if ( j == 1 || j == spalten) 
						if ( i == tabellen_liter && j == spalten ) printf("| %.2f", liter);
						else printf("|");
					else if ( i <= getankte_stellen )
							if ( j == 3) printf("*");
							else printf(" ");
					else printf(" ");
		}
		printf("\n");
	}
	/*
	for ( i = TANK_ANZEIGE_STELLEN + 1; i >= 0; i-- ) {
		for ( j = 1; j <= spalten; j++ ) {
			if ( i == TANK_ANZEIGE_STELLEN + 1 || i == 0 ) {
				if ( j == 1 || j == spalten ) {
					printf("+");
				} else {
					printf("-");
				}
			} else 
			if ( i < TANK_ANZEIGE_STELLEN + 1 || i > 0 ) {
				if ( j == 1 || j == spalten) {
					if ( i == tabellen_liter && j == spalten ) {
						printf("| %.2f", liter);
					} else {
						printf("|");
					}
				} else if ( i <= getankte_stellen ) {
					if ( j == 3) {
						printf("*");
					} else {
						printf(" ");
					}
				} else {
					printf(" ");
				}
			}
		}
		printf("\n");
	}
	*/
}

int main() {
	tankanzeige_horizontal_1(59.10f);
	tankanzeige_horizontal_2(59.10f);
	tankanzeige_horizontal_3(59.10f);
	tankanzeige_vertikal_1(59.10f);
	tankanzeige_vertikal_2(59.10f);

	return 0;
}


