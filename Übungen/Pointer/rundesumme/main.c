#include <stdio.h>
#include "rundesumme.h"

int main() {
	int zahl1 = 1;
	int zahl2 = 2;
	int zahl3 = 3;
	int gesamt = 0;

	runde_summe(&zahl1, &zahl2, &zahl3, &gesamt);
	printf("Gesamt: %d\n", gesamt);
	return 0;
}
