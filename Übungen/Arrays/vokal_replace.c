#include <stdio.h>

#define SATZL 200

void vokalReplace(char *eingabe, int n) {
	char setCharSmall = ' ';
	char setCharBig = ' ';
	int i = 0;
	int j = 0;
	for ( i = 0; i <= n; i++ ) {
		if (i % 5 == 0) setCharSmall = 'a', setCharBig = 'A';
		if (i % 5 == 1) setCharSmall = 'e', setCharBig = 'E';
		if (i % 5 == 2) setCharSmall = 'i', setCharBig = 'I';
		if (i % 5 == 3) setCharSmall = 'o', setCharBig = 'O';
		if (i % 5 == 4) setCharSmall = 'u', setCharBig = 'U';
		for ( j = 0; eingabe[j] != '\0'; j++ ) {
			if (eingabe[j] == 'A' ||
				eingabe[j] == 'E' ||
				eingabe[j] == 'I' ||
				eingabe[j] == 'O' ||
				eingabe[j] == 'U') {
				eingabe[j] = setCharBig;
			}
			if (eingabe[j] == 'a' ||
				eingabe[j] == 'e' ||
				eingabe[j] == 'i' ||
				eingabe[j] == 'o' ||
				eingabe[j] == 'u') {
				eingabe[j] = setCharSmall;
			}
		}
		printf("%s", eingabe);
	}
}

int main() {
	char satz[SATZL];
	printf("Bitte geben Sie einen Satz ein: \n");
	fgets(satz, SATZL, stdin);

	int wiederholungen = 0;
	printf("Wie of sollen die Vokale getauscht werden: \n");
	scanf(" %d", &wiederholungen);

	vokalReplace(satz, wiederholungen);

	return 0;
}
