#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PLANETEN 20
#define MAX_MONDE 100

typedef struct {
	char *name;
	int durchmesser; // in km
} Mond;

typedef struct {
	char *name;
	int durchmesser; // in km
	Mond *monde[MAX_MONDE];
} Planet;

void add_planet(Planet **anchor, char *name, int durchmesser) {
	int i = 0;
	int j = 0;
	while(anchor[i] != NULL) {
		i++;
	}
	//anchor[i] = (Planet*)malloc(sizeof(Planet));
	anchor[i] = calloc(1, sizeof (Planet));
	anchor[i]->name = malloc(strlen(name)+1);
	strcpy(anchor[i]->name, name);
	anchor[i]->durchmesser = durchmesser;
/* 	for(int j = 0; j < MAX_MONDE; j++) {
		anchor[i]->monde[j] = NULL;
	} */
	printf("\nNeuer Planet: %s\n", anchor[i]->name);
}

void add_mond(Planet **anchor, char *namePlanet, char *nameMond, int durchmesser) {
	Mond *neu = (Mond*)malloc(sizeof(Mond));
	neu->name = malloc(strlen(nameMond)+1);
	strcpy(neu->name, nameMond);
	neu->durchmesser = durchmesser;
	int i = 0;
	int j = 0;
	while(anchor[i] != NULL) {
		if(strcmp(anchor[i]->name, namePlanet) == 0 ) {
			while(anchor[i]->monde[j] != NULL) {
				if ( j >= MAX_MONDE ) {
					printf("Fehler! Maximale Mondanzahl ist ueberschritten!\n");
					break;
				}
					printf("%d\n",j);
				j++;
			}
			if( j < MAX_MONDE ) {
				anchor[i]->monde[j] = neu;
				printf("\nNeuer %s Mond: %s\n", anchor[i]->name, anchor[i]->monde[j]->name);
			//	printf("%s i %d j %d\n", anchor[i]->monde[j]->name, i, j);
			}
		}
		i++;
	}
}

void ausgabe(Planet **anchor) {
	printf("\nAusgabe: \n");
	int i = 0;
	int j = 0;
	while(anchor[i] != NULL) {
		printf("%s (%d km)\n",anchor[i]->name, anchor[i]->durchmesser);
		while(anchor[i]->monde[j] != NULL) {
			printf("%*c", strlen(anchor[i]->name), ' ');
			printf(" %s (%d km)\n", anchor[i]->monde[j]->name, anchor[i]->monde[j]->durchmesser);
			j++;
		}
		j = 0;
		i++;
	}
}

void remove_planet(Planet **anchor, char *namePlanet) {
	int i = 0;
	int k = 0;
	while(anchor[k] != NULL) k++;
	while(anchor[i] != NULL) {
		if(strcmp(anchor[i]->name, namePlanet) == 0 ) {
			printf("\nLoesche Planet: %s.\n", anchor[i]->name);
			while(i < k) {
				anchor[i] = anchor[i+1];
				i++;
			}
		}
		i++;
	}
}

void remove_mond(Planet **anchor, char *namePlanet, char *nameMond) {
	int i = 0;
	int j = 0;
	int k = 0;
	while(anchor[i] != NULL) {
		if(strcmp(anchor[i]->name, namePlanet) == 0 ) {
			while(anchor[i]->monde[j] != NULL) {
				while(anchor[i]->monde[k] != NULL) k++;
				if(strcmp(anchor[i]->monde[j]->name, nameMond) == 0 ) {
					printf("\nLoesche %s Mond: %s.\n",anchor[i]->name, anchor[i]->monde[j]->name);
					while(j < k) {
						anchor[i]->monde[j] = anchor[i]->monde[j+1];
						j++;
					}
				}
				j++;
			}
		}
		i++;
	}
}

int main(void) {
	Planet *planeten[MAX_PLANETEN] = { NULL };

	add_planet(planeten, "Mars", 143000);
 	add_mond(planeten, "Mars", "Snikers", 12345);

	add_planet(planeten, "Jupiter", 143000);
	add_mond(planeten, "Jupiter", "Europa", 3100);
	add_mond(planeten, "Jupiter", "Sarah", 100);
	add_mond(planeten, "Jupiter", "Euka", 5000000);

	ausgabe(planeten);

	remove_planet(planeten, "Jupiter");

	ausgabe(planeten);

	add_planet(planeten, "Erde", 143000);
	add_mond(planeten, "Erde", "Mond", 5000);
	add_mond(planeten, "Erde", "Muelldeponie", 500);
	add_mond(planeten, "Erde", "Getarnte Station", 200);

	ausgabe(planeten);

	remove_mond(planeten, "Mars", "Snikers");
	remove_mond(planeten, "Erde", "Getarnte Station");
	remove_mond(planeten, "Erde", "Muelldeponie");

	for(int i = 0; i < 101; i++){
		add_mond(planeten, "Mars", "Snikers", 12345);
	}

	add_planet(planeten, "Jupiter", 143000);
	add_mond(planeten, "Jupiter", "Europa", 3100);
	add_mond(planeten, "Jupiter", "Sarah", 100);
	add_mond(planeten, "Jupiter", "Euka", 5000000);

	ausgabe(planeten);

	
	return 0;
}
