#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Film {
	char *movieTitel;
	int releaseYear;
	// Genre
	// Rating
	// Actors
	struct Film *next;
} Film;

Film *firstMovie = NULL;
Film *lastMovie = NULL;

struct Film *create(char *titel, int year) {
	Film *new = (Film*)malloc(sizeof(Film));
	if(firstMovie == NULL) {
		firstMovie = new;
		lastMovie = firstMovie;
		lastMovie->next = NULL;
	} else {
		lastMovie->next = new;
		lastMovie = lastMovie->next;
		lastMovie->next = NULL;
	}
	lastMovie->movieTitel = malloc(strlen(titel)+1);
	strcpy(lastMovie->movieTitel, titel);
	lastMovie->releaseYear = year;

	return lastMovie;
}

void ausgabe(Film *movie) {
	Film *thisMovie = firstMovie;
	int i = 0;
	while(thisMovie != NULL) {
		printf("%s - Releaseyear %d\n", thisMovie->movieTitel, thisMovie->releaseYear);
		thisMovie = thisMovie->next;
	}
}

int main() {
	create("Godzilla", 1);
	create("King Kong", 2);
	create("Hercules", 3);
	ausgabe(firstMovie);
	ausgabe(firstMovie);

	return 0;
}