#include <stdio.h>

#define TRANSPORTLAST 750

void gesamtlast() {

	// Paket Eingabe und Zähler
	int eingabe_Aktiv = 1;	// Paketgewicht kann eingegeben werden
	int eingabe_Wert = 0;	// Variable für einzelne Eingaben
	int summe_KG = 0;		// Gesamtgewicht
	int pakete_Zaehler = 1;	// Wie viele Pakete wurden eingegeben
	int pakete_Anzahl = 0;	// Speicher für Paketanzahl

	// LKW Zähler
	int lkw_Zaehler = 1; // Gesamtanzahl LKWs
	int lkw_Aktuell = 1; // Aktuell beladener LKW
	int lkw_Schwerster = 0; // LKW mit grösstem Gewicht
	int lkw_Last_Aktuell = 0; // Aktuelle Last im LKW
	int lkw_Last_Groeste_Last = 0; // Höchste Last
	int vollbeladen = 0;

	printf("Geben Sie bitte das Paketgewicht ein:\n");
	printf("(Eingabe 0 für Ende)\n");

	while ( eingabe_Aktiv != 0 ) {
		eingabe_Wert = 0;
		printf("Gewicht %d. Paket: ", pakete_Zaehler);
		scanf(" %d", &eingabe_Wert );
		if ( eingabe_Wert > TRANSPORTLAST ) {
			printf("Transportlast ueberschritten!\n Paket kann nicht geladen werden!\n");
			continue;
		}
		if ( eingabe_Wert < 0 ) {
			printf("Ungueltige Eingabe!\n");
			continue;
		}
		if ( eingabe_Wert == 0 ) {
			pakete_Anzahl += pakete_Zaehler-1;
			pakete_Zaehler = 1;
			eingabe_Aktiv = 0;
		} else {
			summe_KG += eingabe_Wert;
			pakete_Zaehler++;

			if ( lkw_Last_Aktuell == TRANSPORTLAST ) {
				vollbeladen++;
			}

			// LKW zuweisung
			if ( lkw_Last_Aktuell + eingabe_Wert > TRANSPORTLAST ) {
				lkw_Zaehler++;
				lkw_Aktuell++;
				lkw_Last_Aktuell = 0;
			}
			lkw_Last_Aktuell += eingabe_Wert;
			if ( lkw_Last_Aktuell > lkw_Last_Groeste_Last ) {
				lkw_Last_Groeste_Last = lkw_Last_Aktuell;
				lkw_Schwerster = lkw_Aktuell;
			}
		}
	}
	printf("\n///Zusammenfassung////\n");
	printf("Pakete insgesamt: %d\n", pakete_Anzahl);
	printf("Summe Gewicht: %d\n", summe_KG);
	if (summe_KG > 0) {
		printf("Anzahl LKWs: %d\n\n", lkw_Zaehler);
		if ( vollbeladen > 1 ) {
			printf("Es gab %d vollbeladene LKWs.\nMit einer Transportlast von %d kg.", vollbeladen, TRANSPORTLAST);
		} else {
			printf("LKW mit groesster Last:\nLKW Nr. : %d\nTransportierte Last: %d kg\n", lkw_Schwerster, lkw_Last_Groeste_Last);
		}
	}
}

int main() {

	gesamtlast();

	return 0;
}
