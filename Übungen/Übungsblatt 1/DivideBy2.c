/*
Lesen Sie einen Integer-Wert (num >= 0) ein.
Wie oft kann dieser durch 2 geteilt werden,
bis die 1 erreicht wird? Das Ergebnis soll ausgegeben werden.
Vervollständigen Sie folgendes Programm und entfernen Sie den Kommentar.
*/

#include <stdio.h>

int main(void) {
	int count = 0; /* Counts how many divisions we've done. */
	int num; /* The user input. */

	scanf("%d", &num);

	do {
		if (num > 1) {
		num = num / 2;
		count++;
		}
	} while (num > 1);

	printf("%d", count);

  return 0;
}
