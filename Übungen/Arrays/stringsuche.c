#include <stdio.h>

int wortlaenge(char *wort) {
	int i = 0;
	for (i = 0; wort[i] != '\0'; i++) {
	}
	return i;
}

// Funktion stringSuche während der Entwicklung erstellt
// aber zur Ausführung nicht notwendig
// Funktion gibt 1 aus, falls suchbegriff im ziel enthalten ist
int stringSuche(char *ziel, char *suchbegriff) {
	int zielLaenge = wortlaenge(ziel);
	int suchLaenge = wortlaenge(suchbegriff);

	int gefunden = 0;

	int i = 0;
	int j = 0;

	for(i = 0; i <= zielLaenge; i++) {
		for(j = i; j < i + suchLaenge; j++) {
			gefunden = 1;
			if(ziel[j] != suchbegriff[j - i]) {
				gefunden = 0;
				break;
			}
		}
		if (gefunden == 1) {
			break;
		}
	}
	if(gefunden == 1) {
		return 1;
	} else {
		return 0;
	}
}

char *stringPosition(char *ziel, char *suchbegriff) {
	while (*ziel) {
		char *start = ziel;
		char *speicher = suchbegriff;
		//printf("ziel: %s\n", ziel);
		//printf("speicher: %s\n", speicher);
		//printf("start: %s\n", start);

		while (*ziel && *speicher && *ziel == *speicher) {
			ziel++;
			speicher++;
		}
		if (!*speicher) {
				return start;
		}
				
		ziel = start + 1; 
	}
	return NULL;
}

char* suche (char *str, char *such, unsigned int n) {
	char *res = str;
	int i = 0;
	for( i = 0; i < n; i++) {
		res = stringPosition(res, such);
		if(i != n-1) {
			res += 2;
		}
	}
	return res;
}

int main() {

	printf("%s\n", suche("dreierleieierei", "ei", 1) ); // ergibt: eierleieierei 
	printf("%s\n", suche("dreierleieierei", "ei", 3) ); // ergibt: eierei 
	printf("%s\n", suche("dreierleieierei", "ei", 4) ); // ergibt: ei 
	printf("%s\n", suche("barbara macht barbarei", "arba", 2) ); // ergibt: arbarei 
	suche("dreierleieierei", "ei", 1);
	suche("barbara macht barbarei", "asd", 1);

	return 0;
}
