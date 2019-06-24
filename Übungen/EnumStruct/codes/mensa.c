#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum Kennzeichnungen { VEGAN, VEGETARISCH, GLUTENFREI, ALLERGENFREI } Kennzeichnungen;

typedef struct Gericht {
	int kcal;
	char *name;
	Kennzeichnungen inhalt;
	float preis;
	int Speisennummer;
	struct Gericht *next;
} Gericht;

Gericht *create(int kcal, char *name, Kennzeichnungen inh, float geld, int nr) {
	Gericht *neu = calloc(1, sizeof(Gericht)); //(Gericht*)malloc(sizeof(Gericht));
	if ( neu == NULL ) return NULL;
	neu->kcal = kcal;
	neu->name = malloc(strlen(name)+1);
	strcpy(neu->name, name);
	neu->inhalt = inh;
	neu->preis = geld;
	neu->Speisennummer = nr;

	return neu;
}

int comparekcal(Gericht *g1, Gericht *g2) {
	if(g1->kcal > g2->kcal) return 1;
	else if(g1->kcal < g2->kcal) return -1;
	else return 0;
}

void add_sorted(Gericht **anchor, Gericht *neu) {
	printf("Add sorted: %s\n", neu->name);
	while(*anchor != NULL && ((*anchor)->kcal < neu->kcal)) {
		anchor = &(*anchor)->next;
	}
	neu->next = *anchor;
	*anchor = neu;

/* 	Gericht *start = *anchor;
	Gericht *sec = (*anchor)->next;
	int k = sec->kcal;
	if(start->kcal == k) {
		if(strcmp(start->name, sec->name) > 0) {
			Gericht *temp = (*anchor)->next;
			(*anchor)->next = *anchor;
			*anchor = temp->next;
		}
	} */
}



void print_all(Gericht *anchor) {
	char *kenn[] = { "Vegan", "Vegetarisch", "Glutenfrei", "Allergenfrei" };
	printf("Print list: \n");
	Gericht *temp = anchor;
	while(temp != NULL) {
		printf("%s - %.2f Geld (%s, %d kcal, Speisennummer: %d)\n", temp->name, temp->preis, kenn[temp->inhalt], temp->kcal, temp->Speisennummer );
		temp = temp->next;
	}
}

int main() {
	Gericht *liste = NULL;
	
	add_sorted( &liste, create(1, "Schockolade", GLUTENFREI, 50, 20) );
	add_sorted( &liste, create(20, "Reis", VEGAN, 3.5, 1) );
	add_sorted( &liste, create(50, "Kuh-Milch", ALLERGENFREI, 100, 5) );
	add_sorted( &liste, create(20, "Xhemicalie-X", VEGETARISCH, 2, 10) );
	print_all(liste);


	return 0;
}
