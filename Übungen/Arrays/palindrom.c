#include <stdio.h>

int wortlaenge(char *wort) {
	int i = 0;
	for ( i = 0; wort[i] != '\0'; i++ ) {
		// i wird gezaehlt
	}
	return i;
}

char *tolowercase(char *wort) {
	int i = 0;
	int offset = 32;
	for ( i = 0; wort[i] != '\0'; i++ ) {
		if ( wort[i] > 64 && wort[i] < 91 ) {
			wort[i] += offset;
		}
	}
}

int main() {
	char test[] = "AnNa";
	tolowercase(test);
	int laenge = wortlaenge(test);

	int palindrom = 0;

	int i = 0;
	int j = 0;

	for ( i = 0, j = laenge - 1; i < laenge; i++, j-- ) {
		printf("i: %d %c j: %d %c\n", i, test[i], j, test[j]);
		if ( test[i] == test[j] ) {
			palindrom = 1;
		} else {
			palindrom = 0;
			break;
		}
	}

	if ( palindrom ) {
		printf("%s ist ein Palindrom!\n", test);
	} else {
		printf("%s ist kein Palindrom!\n", test);
	}

	return 0;
}
