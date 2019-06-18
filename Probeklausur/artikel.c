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

void anlegen(struct Artikel **anchor, int artikelnummer, char *artText) {
	int i = 0;
	while(anchor[i] != NULL) {
		i++;
	}
	anchor[i] = (struct Artikel*)malloc(sizeof(struct Artikel));
	anchor[i]->artnr = artikelnummer;
	anchor[i]->bezeichnung = malloc( strlen(artText)+1 );
	strcpy(anchor[i]->bezeichnung, artText);
}

void bewerten(struct Artikel **anchor, int nr, char *bewertungstext, int sterne) {
	struct Bewertung *neu = (struct Bewertung*)malloc(sizeof(struct Bewertung));
	neu->text = malloc( strlen(bewertungstext)+1 );
	strcpy(neu->text, bewertungstext);
	neu->punkte = sterne;
	int i = 0;
	while(anchor[i] != NULL) {
		if(anchor[i]->artnr == nr) {
			neu->next = anchor[i]->bewertungen;
			anchor[i]->bewertungen = neu;
		}
		i++;
	}
}

void anzeigen(struct Artikel **artikel) {
	int i = 0;
	int j = 0;
	while(artikel[i] != NULL) {
		printf("Artikel: %d - %s\n", artikel[i]->artnr, artikel[i]->bezeichnung);
		
		while(artikel[i]->bewertungen != NULL) {
			printf("%*c", -9+artikel[i]->bewertungen->punkte, ' ');
			for(j = 0; j < artikel[i]->bewertungen->punkte; j++) {
				printf("*");
			}
			printf(" %s\n", artikel[i]->bewertungen->text);
			artikel[i]->bewertungen = artikel[i]->bewertungen->next;
		}
		printf("\n");
		i++;
	}
}

int main() {

	struct Artikel *artikel[MAX_ARTIKEL] = { NULL };

	anlegen(artikel, 12345, "Hoerbuch Biene Maja");
	bewerten(artikel, 12345, "Hoere ich zum Einschlafen", 4);
	bewerten(artikel, 12345, "Mehr Handlung!", 1);


	anlegen(artikel, 4549, "Smartphone Universum III");
	bewerten(artikel, 4549, "Voll das krasse Handy", 5);

	anzeigen(artikel);
	anzeigen(artikel);

	return 0;
}
