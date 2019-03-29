#include <stdio.h>

int main() {

	int a = 0;
	int b = 0;
	int c = 0;

	printf("Gegeben ist die quadratische Gleichung: \n");
	printf("f(x) = ax%c%c + bx + c\n\n", 0xc2, 0xb2);
	printf("Bitte geben Sie die Werte für a, b und c ein.\n");
	printf("a: ");
	scanf("%i", &a);
	printf("b: ");
	scanf("%i", &b);
	printf("c: ");
	scanf("%i", &c);

	if ( a > 0 ) {
		printf("Parabel\n");
	} else if ( a == 0 && b != 0 && c != 0 ) {
		printf("Gerade\n");
	} else if ( a == 0 && b != 0 && c == 0 ) {
		printf("Gerade durch Nullpunkt\n");
	} else if ( a == 0 && b == 0 && c != 0 ) {
		printf("Parallele zur x-Achse\n");
	} else if ( a == 0 && b == 0 && c == 0 ) {
		printf("x-Achse\n");
	}

	return 0;
}
