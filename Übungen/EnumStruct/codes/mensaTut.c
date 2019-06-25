#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Datentypen
typedef enum { VEGETARISCH, VEGAN, GLUTENFREI, ALLERGENFREI } Kennzeichen;
typedef struct Gericht {
	int speisenr;
	int preis;
	char *name;
	int energiegehalt;
	Kennzeichen kennzeichen[4];
	struct Gericht *next;
} Gericht;

int foodcmp(Gericht *links, Gericht *rechts) {
	if(links->energiegehalt == rechts->energiegehalt) {
		return strcmp(links->name, rechts->name);
	} else {
		// return (links->energiegehalt - rechts->energiegehalt);
		if(links->energiegehalt < rechts->energiegehalt) return -1;
		else if(links->energiegehalt > rechts->energiegehalt) return 1;
		return 0;
	}
}

void sortiert_einfuegen(Gericht **anker, Gericht *neu) {
	while( *anker != NULL && (foodcmp(*anker, neu) < 0) ) {
		anker = &((*anker)->next);
	}
	neu->next = *anker;
	*anker = neu;
}

void loesche(Gericht **anker, int gerichts_id) {
	
}

int main() {
	Gericht *anfang = NULL;

	Gericht *neu1 = malloc(sizeof(Gericht));
	strcpy(neu1->name, "Feuertopf");
	neu1->energiegehalt = 120;
	neu1->kennzeichen[0] = ALLERGENFREI;
	neu1->kennzeichen[1] = VEGAN;
	neu1->preis = 250;
	neu1->speisenr = 1;
	sortiert_einfuegen(&anfang, neu1);

	strcpy(neu1->name, "Wiener Schnietzel");
	neu1->energiegehalt = 829;
	neu1->preis = 545;
	neu1->speisenr = 2;
	sortiert_einfuegen(&anfang, neu1);

	strcpy(neu1->name, "Vanillejoghurt");
	neu1->energiegehalt = 500;
	neu1->kennzeichen[0] = ALLERGENFREI;
	neu1->preis = 1000;
	neu1->speisenr = 3;
	sortiert_einfuegen(&anfang, neu1);

	return 0;
}
