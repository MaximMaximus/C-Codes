#include <stdio.h>

void stringremover(char *ziel, char *such) {
	int i = 0;
	int j = 0;
	int k = 0;
	for ( i = 0; ziel[i] != NULL; i++ ) {
		for ( j = 0; such[j] != NULL; j++ ) {
			if ( ziel[i] == such[j] ) {
				for ( k = i; ziel[k] != NULL; k++ ) {
					ziel[k] = ziel[k+1];
				}
				i = 0;
			}
		}
	}
}

int main() {
	char s1[] = "eins zwei drei";
	char s2[] = "drei";

	stringremover(s1, s2);
	printf("%s\n", s1);

	return 0;
}
