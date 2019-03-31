#include <stdio.h>

int main() {

	// boolen fuer richtige Datumseingabe
	int eingabe = 0;
	int datenErhalten = 0;

	// boolen loescht den Bildschirm und gibt ein Fehler aus
	int eingabeClear = 0;

	// Speicher fuer Monatstage
	int monatsTage = 0;

	// boolen fuer Werteuebergabe
	int werteJahrEins = 0;

	// Speicher fuer erstes Datum
	int tagEins = 0;
	int monatEins = 0;
	int jahrEins = 0;

	// Speicher fuer zweites Datum
	int tagZwei = 0;
	int monatZwei = 0;
	int jahrZwei = 0;

	// Speicher fuer den berechneten Tagesabstand
	int anzahlTage = 0;

	// boolen fuer Schaltjahr
	int schaltjahrEins = 0;
	int schaltjahrZwei = 0;

	system("clear");

	printf("Berechnung der Tage\n");
	// Eingabeueberpruefung
	do {
		// loescht den Bildschirm bei falscher Eingabe
		if ( eingabeClear == 1) {
			system("clear");
			printf("Fehler! Ungueltiges Datum!\n");
		}

		printf("Bitte geben Sie das erste datum ein (Form TT.MM.JJJJ): ");
		fflush(stdin);
		scanf("%d.%d.%d", &tagEins, &monatEins, &jahrEins);
	
		// Schaltjahrtest
		if ( jahrEins % 400 == 0 ) {
			schaltjahrEins = 1;
		} else if ( jahrEins % 100 == 0 ) {
			schaltjahrEins = 0;
		} else if ( jahrEins % 4 == 0 ) {
			schaltjahrEins = 1;
		}

		// Puefen ob ein gueltiger Tag eingegeben wurde	
		switch (monatEins) {
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12: monatsTage += 31; break;
		case 2: 
				if ( schaltjahrEins ) {
					monatsTage += 29;
				} else {
					monatsTage += 28;
				} break; // ohne Schaltjahre
		default: monatsTage += 30;
		}	

		if ( tagEins < 1 || tagEins > monatsTage ) {
			eingabe = 0;
			monatsTage = 0;
		} else if ( monatEins < 1 || monatEins > 12 ) {
			eingabe = 0;
		} else if ( jahrEins < 1 || jahrEins > 9999 ) {
			eingabe = 0;
		} else {
			eingabe = 1;
		}
	
		// Werteuebergabe
		if ( eingabe == 1 ) {
			// Die erste Werteuebergabe erfolgt
			werteJahrEins = 1;
		}

		// initiert system("clear") bei falscher Eingabe
		if ( eingabe == 0 ) {
			eingabeClear = 1;
		} else {
			eingabeClear = 0;
		}

	} while ( werteJahrEins == 0 );

	// Speicher loeschen
	monatsTage = 0;
	eingabe = 0;
	eingabeClear = 0;

	// Eingabeueberpruefung
	do {
		// loescht den Bildschirm bei falscher eingabe
		if ( eingabeClear == 1 ) {
			system("clear");
			printf("Fehler! Ungueltiges Datum!\n");
		}

		printf("Bitte geben Sie das zweite datum ein (Form TT.MM.JJJJ): ");
		fflush(stdin);
		scanf("%d.%d.%d", &tagZwei, &monatZwei, &jahrZwei);
		
		// Schaltjahrtest
		if ( jahrZwei % 400 == 0 ) {
			schaltjahrZwei = 1;
		} else if ( jahrZwei % 100 == 0 ) {
			schaltjahrZwei = 0;
		} else if ( jahrZwei % 4 == 0 ) {
			schaltjahrZwei = 1;
		}

		// Puefen ob ein gueltiger Tag eingegeben wurde
		switch (monatZwei) {
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12: monatsTage += 31; break;
		case 2: 
				if ( schaltjahrZwei ) {
					monatsTage += 29;
				} else {
					monatsTage += 28;
				} break; // ohne Schaltjahre
		default: monatsTage += 30;
		}	

		if ( tagZwei < 1 || tagZwei > monatsTage ) {
			eingabe = 0;
			monatsTage = 0;
		} else if ( monatZwei < 1 || monatZwei > 12 ) {
			eingabe = 0;
		} else if ( jahrZwei < 1 || jahrZwei > 9999 ) {
			eingabe = 0;
		} else if ( jahrZwei < jahrEins ) {
			eingabe = 0;
		} else if ( monatZwei < monatEins ) {
			eingabe = 0;
		} else if ( tagZwei < tagEins ) {
			eingabe = 0;
		} else {
			eingabe = 1;
		}
	
		// Werteuebergabe
		if ( eingabe == 1 ) {
			// Die erste Werteuebergabe erfolgt
			datenErhalten = 1;

			// Speicher loeschen
			monatsTage = 0;
			eingabe = 0;
			eingabeClear = 0;
		}

		// initiert system("clear") bei falscher Eingabe
		if ( eingabe == 0 ) {
			eingabeClear = 1;
		} else {
			eingabeClear = 0;
		}

	} while ( datenErhalten == 0 );

	// Ausgabe
	printf("\nIhr erstes Datum: %d.%d.%d\n", tagEins, monatEins, jahrEins);
	printf("Ihr zweites Datum: %d.%d.%d\n", tagZwei, monatZwei, jahrZwei);

	// informiert ueber Schaltjahr
	if ( schaltjahrEins ) {
		printf("%d ist ein Schaltjahr.\n", jahrEins );
	}

	if ( schaltjahrZwei ) {
		printf("%d ist ein Schaltjahr.\n", jahrZwei );
	}

	// loop Berechnung der Tage innerhalb des gleichen Jahres
	if ( jahrEins == jahrZwei ) {

		int i = 0;

		// damit der Endwert stimmt
		anzahlTage -= tagEins;

		for ( i = monatEins; i <= monatZwei; i++) {
			printf("ianzahlTage: %d\n", anzahlTage );
			if ( monatEins == monatZwei ) {
				anzahlTage = tagZwei - tagEins;
			} else if ( i == monatZwei ) {
				anzahlTage += tagZwei;
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
							if ( schaltjahrEins ) {
								anzahlTage += 29;
							} else {
								anzahlTage += 28;
							} break;
					default: anzahlTage += 30;
				}
			}
		}
	} else if ( jahrEins != jahrZwei ) {

		// Berechnung der Tage innerhalb unterschiedlicher Jahre
		int jahresDifferenz = 0;
		jahresDifferenz = jahrZwei - jahrEins;
		printf("jahresDifferenz: %d\n", jahresDifferenz);

		// Uebergabe des Jahreswert, damit bei jedem Durchlauf auf Schaltjahr geprueft werden kann
		int schaltjahrTest = jahrEins;

		// damit der Endwert stimmt
		anzahlTage -= tagEins;

		int i = 0;
		int j = 0;

		// x fuer Monate
		int x = 12;
		// Startmonat
		int jMonat = monatEins;

		// loop fuer die Jahre
		for ( i = 0; i <= jahresDifferenz; i++) {

			// Schaltjahrtest
			if ( (schaltjahrTest) % 400 == 0 ) {	
				schaltjahrEins = 1;
			} else if ( (schaltjahrTest) % 100 == 0 ) {
				schaltjahrEins = 0;
			} else if ( (schaltjahrTest) % 4 == 0 ) {
				schaltjahrEins = 1;
			}

			if ( schaltjahrEins == 1 ) {
				printf("%d ist ein Schaltjahr\n", schaltjahrTest);
			}

			// beim zweiten loop Durchlauf muss ab dem ersten Monat gerechnet werden
			if ( i == 1 ) {
			 	jMonat = 1;
			 } 

			// loop fuer die Monate
			for ( j = jMonat; j <= x; j++) {

				// beim Endjahr wird x auf den eingegebenen Monat gesetzt
				if ( i == jahresDifferenz ) {
					x = monatZwei;

					// wenn der Endwert erreicht ist soll der eingegebene Tag addiert werden
					if ( j == monatZwei ) {
						anzahlTage += tagZwei;
						break;
					}
				}
				switch (j) {
					case 1:
					case 3:
					case 5:
					case 7:
					case 8:
					case 10:
					case 12: anzahlTage += 31; break;
					case 2: 
							if ( schaltjahrEins ) {
								anzahlTage += 29;
							} else {
								anzahlTage += 28;
							} break;
					default: anzahlTage += 30;
				}
				//printf("ianzahlTage: %d, %d\n", anzahlTage, j );
			}
			// um das nächste Jahr zu testen
			schaltjahrTest+=1;
			// muss auf 0 gesetzt werden, da sonst alle drauffolgenden Jahre, Schaltjahre sind
			schaltjahrEins = 0;
		}
	}	

	printf("\nGesamttage: %d\n", anzahlTage);

	printf("Vergangene Tage seit dem %d.%d.%d: %d\n", tagEins, monatEins, jahrEins, anzahlTage );

	return 0;
}
