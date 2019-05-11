#include <stdio.h>

#define MAX_LAENGE 200

int wortlaenge(char *wort) {
	int i = 0;
	for ( i = 0; wort[i] != '\0'; i++ ) {
		// i wird gezaehlt
	}
	return i;
}

int main() {
	//char info[] = "Informatik";
	char info[MAX_LAENGE];
	fgets(info, MAX_LAENGE, stdin);

	int laenge = wortlaenge(info);
	printf("Wortlaenge: %d\n", laenge - 1);

	// fgets integriert automatisch ein \n am ende vom Array
	if ( info[laenge-1] == '\n' ) {
		printf("Newline\n");
	}
	// \n löschen
	info[laenge-1] = '\0';

	int i = 0;
	for ( i = 0; i < laenge; i++ ) {
		info[i-1] = ' ';
		printf("%s\n", info);
	}

	return 0;
}
