#include <stdio.h>

int wortlaenge(char *wort) {
	int i = 0;
	for ( i = 0; wort[i] != '\0'; i++ ) {
		// i wird gezaehlt
	}
	return i;
}

int main() {
	char info[] = "Informatik";

	int laenge = wortlaenge(info);
	int i = 0;
	for ( i = 0; i < laenge; i++ ) {
		info[i-1] = ' ';
		printf("%s\n", info);
	}

	return 0;
}
