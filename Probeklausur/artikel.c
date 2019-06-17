#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ARTIKEL 100

struct Artikel {
	unsigned int artnr;
	char *bezeichnung;
	struct Bewertung *bewertungen;
};

struct Bewertung {
	char *text;
	int punkte;
	struct Bewertung *next;
};

void anlegen(struct Artikel *art, int artikelnummer, char *artText) {
/* 	int i = 0;
	for ( i = 0; i < MAX_ARTIKEL; i++ ) {
		if (art[i][0].artnr == 0 && art[i][0].bezeichnung == '\0') {
			art[i][0].artnr = artikelnummer;
			strcpy(art[i][0].bezeichnung, artText);
		}
	} */
	int i = 0;
	for ( i = 0; i < MAX_ARTIKEL; i++ ) {
		art[i] = (struct Artikel*)malloc(sizeof(struct Artikel));
		if (art->artnr == 0 && art->bezeichnung == '\0') {
			art->artnr = artikelnummer;
			strcpy(art->bezeichnung, artText);
		}
		art++;
	}
}

void bewerten(struct Artikel *artikel, int nr, char *bewertungstext, int sterne) {
	int i = 0;
	for ( i = 0; i < MAX_ARTIKEL; i++ ) {
		if (artikel[i].artnr == nr) {
			strcpy(artikel[i].bewertungen->text, bewertungstext);
			artikel[i].bewertungen->punkte = sterne;
			//artikel[i]bewertungen->next = (*artikel)->bewertungen;
		}
	}
}


int main() {
	struct Artikel *artikel[MAX_ARTIKEL] = { NULL };

	anlegen(artikel, 12345, "Hörbuch Biene Maja");
	//bewerten(artikel, 12345, "Höre ich zum Einschlafen", 4);
	//bewerten(artikel, 12345, "Mehr Handlung!", 1);

	//anlegen(artikel, 4549, "Smartphone Universum III");
	//bewerten(artikel, 4549, "Voll das krasse Handy", 5);

	//anzeigen(artikel);

	return 0;
}