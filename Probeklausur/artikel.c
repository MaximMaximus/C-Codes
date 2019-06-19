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
		struct Bewertung *temp = artikel[i]->bewertungen;
		while(temp != NULL) {
			printf("%*c", -8+temp->punkte, ' ');
			for(j = 0; j < temp->punkte; j++) {
				printf("*");
			}
			printf(" %s\n", temp->text);
			temp = temp->next;
		}
		printf("\n");
		i++;
	}
}

int main() {
	//system("cls");
	struct Artikel *artikel[MAX_ARTIKEL] = { NULL };

	anlegen(artikel, 12345, "Hoerbuch Biene Maja");
	bewerten(artikel, 12345, "Hoere ich zum Einschlafen", 4);
	bewerten(artikel, 12345, "Mehr Handlung!", 1);
	//printf("Artikelnummer: %d\nArtikelbezeichnung: %s\n", artikel[0]->artnr, artikel[0]->bezeichnung);
	//printf("Bewertung: %s\n", artikel[0]->bewertungen->text);
	//printf("Bewertung: %s\n", artikel[0]->bewertungen->next->text);

	anlegen(artikel, 4549, "Smartphone Universum III");
	bewerten(artikel, 4549, "Voll das krasse Handy", 5);
	bewerten(artikel, 4549, "Wo ist Akku", 1);
	//printf("Artikelnummer: %d\nArtikelbezeichnung: %s\n", artikel[1]->artnr, artikel[1]->bezeichnung);
	//printf("Bewertung: %s\n", artikel[1]->bewertungen->text);

	anzeigen(artikel);

	return 0;
}
