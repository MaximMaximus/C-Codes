// a short demonstration of the bitwise operator

#include <stdio.h>

int main()
{

	int a;
	int testLaenge;
	int testWert;
	int i;
	int j;

	printf("Bitte den Startwert a eingeben: \n");
	fflush(stdin);
	scanf("%i", &a);

	printf("Bitte die Testlaenge eingeben: \n");
	fflush(stdin);
	scanf("%i", &testLaenge);

	printf("Bitte Test Wert eingeben: \n");
	fflush(stdin);
	scanf("%i", &testWert);


	for ( i = 0; i < testLaenge; i++)
	{
		a <<= testWert;
		printf("a %i: %i\n", i, a);
	}


	for ( j = testLaenge; j >= 1; j--)
	{
		a >>= testWert;
		printf("a %i: %i\n", j, a);
	}

	return 0;
}
