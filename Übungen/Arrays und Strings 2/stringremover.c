#include <stdio.h>

void stringremover(char *ziel, char *such) {
	int i = 0;
	int j = 0;
	int k = 0;
	int wort = 0;

	while(ziel[i] != '\0') {
		j = 0; wort = 1;

		while(such[j] != '\0') {
			if(such[j] != ziel[i+j]) {
				wort = 0;
				break;
			}
			j++;
		}

		if ( wort ) {
			for ( k = i+j; ziel[k] != '\0'; k++ ) {
				printf("%s\n", ziel);
				ziel[k-j] = ziel[k];
			}
			ziel[k-j] = '\0';
		}
		i++;
	}

	for (i = 0; ziel[i] != NULL; i++) {
		while( ziel[i] == ' ' && ziel[i+1] == ' ') {
			for ( k = i; ziel[k] != NULL; k++ ) {
				ziel[k] = ziel[k+1];
			}
		}
	}
}

int main() {
	char s1[] = "eins zwei drei ";
	char s2[] = "drei";

	stringremover(s1, s2);
	printf("%s\n", s1);

	return 0;
}
