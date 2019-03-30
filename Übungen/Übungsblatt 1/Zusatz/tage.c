#include <stdio.h>

int main() {

	// boolen fuer richtige Datumseingabe
	int eingabe = 0;

	// boolen loescht den Bildschirm und gibt ein Fehler aus
	int eingabeClear = 0;

	// Speicher fuer Monatstage
	int monatsTage = 0;

	// Speicher fuer Benutzereingabe
	int tag = 0;
	int monat = 0;
	int jahr = 0;

	// Speicher fuer den berechneten Tagesabstand
	int anzahlTage = -1;

	// boolen fuer Schaltjahr
	int schaltjahr = 0;

	system("clear");

	// Eingabeueberpruefung
	do {
		printf("Berechnung der Tage\n");
		// loescht den Bildschirm bei falscher eingabe
		if ( eingabeClear == 1) {
			system("clear");
			printf("Fehler! Ungueltiges Datum!\n");
		}
		printf("Bitte geben Sie ein datum ein (Form TT.MM.JJJJ): ");
		fflush(stdin);
		scanf("%d.%d.%d", &tag, &monat, &jahr);

		// Schaltjahrtest
		if ( jahr % 400 == 0 ) {
			schaltjahr = 1;
		} else if ( jahr % 100 == 0 ) {
			schaltjahr = 0;
		} else if ( jahr % 4 == 0 ) {
			schaltjahr = 1;
		}

		// Puefen ob ein gueltiger Tag eingegeben wurde
		switch (monat) {
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12: monatsTage += 31; break;
		case 2: 
				if ( schaltjahr ) {
					monatsTage += 29;
				} else {
					monatsTage += 28;
				} break;
		default: monatsTage += 30;
		}	

		if ( tag < 1 || tag > monatsTage ) {
			eingabe = 0;
			monatsTage = 0;
		} else if ( monat < 1 || monat > 12 ) {
			eingabe = 0;
		} else if ( jahr < 1 || jahr > 9999 ) {
			eingabe = 0;
		} else {
			eingabe = 1;
		}

		// initiert system("clear") bei falscher Eingabe
		if ( eingabe == 0 ) {
			eingabeClear = 1;
		} else {
			eingabeClear = 0;
		}

	} while ( eingabe == 0 );

	printf("\nIhr Datum: %d.%d.%d\n", tag, monat, jahr);

	// informiert ueber Schaltjahr
	if ( schaltjahr ) {
		printf("%d ist ein Schaltjahr.\n", jahr );
	}

	// loop rechnet die Tage zusammen
	int i = 0;

	for ( i = 1; i <= monat; i++) {
		if ( i == monat ) {
			anzahlTage += tag;
		} else {
			switch (i) {
				case 1:
				case 3:
				case 5:
				case 7:
				case 8:
				case 10:
				case 12: anzahlTage += 31; break;
				case 2: 
						if ( schaltjahr ) {
							anzahlTage += 29;
						} else {
							anzahlTage += 28;
						} break; // ohne Schaltjahre
				default: anzahlTage += 30;
			}
		}
	}

	printf("\nGesamttage: %d\n", anzahlTage);

	printf("Vergangene Tage seit dem 01.01.%d: %d\n", jahr, anzahlTage );

	return 0;
}
