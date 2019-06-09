#include <stdio.h>

// a)
enum Farben { SCHELLEN = 0, HERZ, GRAS, EICHEL = 3 };
enum Symbole { SIEBENER = 0, ACHTER, NEUNER, ZEHNER, UNTER, OBER, KOENIG, SAU = 7 };
enum Boolen { FALSCH = 0, WAHR = 1 };

// b)
struct Spielkarte {
	enum Farbe farbe;
	enum Symbole symbol;
};

// c)
enum Boolen teste_vollstaendigkeit(struct Spielkarte karte[], int laenge) {
	int farbenzaehler[4] = {0};
	int symbolzaehler[8] = {0};
	int i = 0;

	for ( i = 0; i < laenge; i++ ) {
		farbenzaehler[karte[i].farbe]++;
		symbolzaehler[karte[i].symbol]++;
	}
	for ( i = 0; i < 4; i++ ) {
		if ( farbenzaehler[i] != 8 ) return FALSCH;
	}
	for ( i = 0; i < 8; i++ ) {
		if ( symbolzaehler[i] != 4 ) return FALSCH;
	}
	return WAHR;
}

// d)
int zaehlwerte_summieren(struct Spielkarte karte[], int laenge) {
	int summe = 0;
	int i = 0;

	for ( i = 0; i < laenge; i++ ) {
		switch (karte[i].symbol) {
		case UNTER: summe += 2; break;
		case OBER: summe += 3; break;
		case KOENIG: summe += 4; break;
		case ZEHNER: summe += 10; break;
		case SAU: summe += 11; break;
		default:
			break;
		}
	}
	return summe;
}

void swap(struct Spielkarte *a, struct Spielkarte *b) {
	struct Spielkarte temp = *a;
	*a = *b;
	*b = temp;
}

// e)
struct Spielkarte *stichkarte(struct Spielkarte stich[]) {
	int i = 0;
	int j = 0;

	for ( i = 0; i < 3; i++ ) {
		for ( j = 0; j < 3; j++ ) {
			if ( stich[j].symbol < stich[j+1].symbol ) swap( &stich[j], &stich[j+1] );
		}
	}

	for ( i = 0; i < 3; i++ ) {
		for ( j = 0; j < 3; j++ ) {
			if ( (stich[j].farbe < stich[j+1].farbe) && (stich[j].symbol == stich[j+1].symbol) ) swap( &stich[j], &stich[j+1] );
		}
	}
	return stich;
}



int main() {
	int i = 0, f, s;

	struct Spielkarte karten_unvollstaendig[] = { {SCHELLEN, ZEHNER}, {EICHEL, SAU }, {GRAS, UNTER} };
	
	struct Spielkarte karten[32];

	// Initialisierung des vollstaendigen Kartenspiels mit 32 Karten
	for(f = 0; f < 4; f++){
		for(s = 0; s < 8; s++, i++) {
			karten[i].farbe  = f; // f und s haben jeweils den int-Wert, den auch die
			karten[i].symbol = s; // Konstanten GRAS, SCHELLEN, ... SIEBENER, ACHTER, ... einnehmen
		}
	}

	// nachfolgenden einfach zu Beginn die Zeilen auskommentieren mit den
	// Funktionen, die Sie noch nicht implementiert haben:
	
	// c) Vollstaendigkeit pruefen
	printf("vollständig: %d (richtig ist 0)\n", teste_vollstaendigkeit(karten_unvollstaendig, 3));
	printf("vollständig: %d (richtig ist 1)\n", teste_vollstaendigkeit(karten, 32));
		// Manipulation des vollstaendigen Kartenspiels, so dass eine Karte doppelt vorkommt:
	karten[17].farbe = SCHELLEN; karten[17].symbol = ACHTER; 
	printf("vollständig: %d (richtig ist 0)\n", teste_vollstaendigkeit(karten, 32));

	// d) Zaehlwerte pruefen
	printf("Zaehlwerte : %3d (richtig ist 23)\n", zaehlwerte_summieren(karten_unvollstaendig, 3));
	printf("Zaehlwerte : %3d (richtig ist 120)\n", zaehlwerte_summieren(karten, 32));

	// e) Stiche pruefen; bitte ggf. die Konstantennamen anpassen
	struct Spielkarte hand1[] = { {GRAS,ACHTER}, {GRAS,NEUNER}, {GRAS,SAU}, {GRAS,SIEBENER} };
	struct Spielkarte *stich; // ggf. anpassen, falls Sie keine Adresse sondern die Struktur an sich zurueckgeben
	stich = stichkarte(hand1);
	printf("Stich 1:     %s\n", (stich->farbe==GRAS&&stich->symbol==SAU)?"passt":"passt nicht");
	struct Spielkarte hand2[] = { {GRAS,ACHTER}, {SCHELLEN,UNTER}, {HERZ,UNTER}, {GRAS,SIEBENER} };
	stich = stichkarte(hand2);
	printf("Stich 2:     %s\n", (stich->farbe==HERZ&&stich->symbol==UNTER)?"passt":"passt nicht");
	struct Spielkarte hand3[] = { {HERZ,ZEHNER}, {EICHEL,UNTER}, {EICHEL,OBER}, {HERZ,SIEBENER} };
	stich = stichkarte(hand3);
	printf("Stich 3:     %s\n", (stich->farbe==EICHEL&&stich->symbol==OBER)?"passt":"passt nicht");
	
	return 0;
}
