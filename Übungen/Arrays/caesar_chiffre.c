#include <stdio.h>

#define MAX 99

void caesarChiffre(char *text, int n) {
	int offset = n;
	int i = 0;
	for ( i = 0; text[i] != '\0'; i++ ) {
		if ( text[i] >= 65 && text[i] <= 90 ) {
			text[i] += offset;
			if ( text[i] > 90 ) {
				text[i] -= 26;
			}
		}
			if ( text[i] >= 97 && text[i] <= 122 ) {
			text[i] += offset;
			if ( text[i] > 122 ) {
				text[i] -= 26;
			}
		}
	}
	printf("%s", text);
}

int main() {
	int key = 0;
	printf("Geben Sie den Verschluesselungs Schluessel ein: \n");
	scanf(" %d", &key);
	fflush(stdin);

	char text[MAX];
	printf("Geben Sie ihre Nachricht ein: \n");
	fgets(text, MAX, stdin);

	caesarChiffre(text, key);

	return 0;
}
