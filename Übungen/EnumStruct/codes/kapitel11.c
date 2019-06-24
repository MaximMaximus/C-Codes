#include <stdio.h>
#include <stdlib.h>

// 11. Script Seite 209
struct Person
{
	char name[10];
	int alter;
	double gewicht;
};

// 11. Script Seite 210
void irgendeine_funktion()
{
	struct Person2
	{
		char name[10];
		int alter;
		double gewicht;
	} willi = {"Wilhelm", 21, 69.1},
	  fritz, // Platzhalter
		lisa = {"Lisa", 24, 51.2};

	fritz.alter = 18;
	fritz.gewicht = 72.8;
	strcpy(fritz.name, "Fritz");

	printf("Alter von %s ist %d.\n", fritz.name, fritz.alter);
}

// 11. Script Seite 211
enum Titel
{
	KEIN,
	DR,
	PROF,
	PROF_DR
};
struct Name
{
	enum Titel titel;
	char vornmae[20];
	char nachname[30];
};
struct Adresse
{
	struct Name adressat;
	char strasse[100];
	int hausnummer;
	int plz;
	char ort[50];
};

// 11. Script Seite 212
struct Datum
{
	int tag;
	int monat;
};

// 11. Script Seite 215
struct Punkt
{
	double x;
	double y;
};
void add(struct Punkt p1, struct Punkt p2, struct Punkt *p3)
{
	p3->x = p1.x + p2.x;
	p3->y = p1.y + p2.y;
}

// 11. Script Seite 217
struct Punkt kopiere_punkt(struct Punkt p)
{
	struct Punkt *neu = malloc(sizeof(struct Punkt));
	neu->x = p.x;
	neu->y = p.y;
	return *neu;
}

int main()
{
	// 11. Script Seite 209
	struct Person willi = {"Wilhelm", 81, 73.2};

	printf("Name: %s\n", willi.name);
	printf("Alter: %d\n", willi.alter);
	printf("Gewicht: %5.2lf\n", willi.gewicht);

	// 11. Script Seite 210
	irgendeine_funktion();

	// 11. Script Seite 211
	struct Adresse max_muster;
	max_muster.adressat.titel = KEIN;
	strncpy(max_muster.adressat.vornmae, "Maximilian", 20);
	strncpy(max_muster.adressat.nachname, "Muster", 30);
	strncpy(max_muster.strasse, "Universitätstr.", 100);
	max_muster.hausnummer = 31;
	max_muster.plz = 93053;
	strncpy(max_muster.ort, "Regensburg", 50);

	// 11. Script Seite 212
	struct Datum feiertage[11];
	feiertage[0].tag = 1;
	feiertage[0].monat = 1;
	feiertage[10].tag = 26;
	feiertage[10].monat = 12;

	// 11. Script Seite 213
	struct Adresse *person = &max_muster;
	// 1. Variante
	(*person).hausnummer = 20;
	strncpy((*person).ort, "Regensburg", 50);
	// 2. Variante
	person->hausnummer = 20;
	strncpy(person->ort, "Regensburg", 50);
	strncpy(person->adressat.nachname, "Muster", 30);

	printf("Name %s Wohnort %s Hausnummer %d\n", person->adressat.nachname, person->ort, person->hausnummer);

	struct Punkt a;
	a.x = 3.2;
	a.y = 4.7;
	struct Punkt b;
	b.x = -4.6;
	b.y = 9.2;
	struct Punkt c;
	add(a, b, &c);
	printf("c = (%g, %g)\n", c.x, c.y);

	struct Punkt *z;
	*z = kopiere_punkt(a);
	printf("z = %g, %g\n", z->x, z->y);
	free(z);
	return 0;
}


