// Standalone code for ARMSTRONGZAHL

#include <stdio.h>
#include <stdlib.h>

int benutzerEingabe(int *zahl, int *userZahl)
{
	*zahl = 0;
	int abfrage = 0;

	while(abfrage == 0)
	{
		printf("Bitte geben Sie eine Zahl ein: ");
		fflush(stdin);
		scanf("%d", zahl);

		if(*zahl == (int)*zahl && !(*zahl <= 0))
		{
			abfrage = 1;
			*userZahl = *zahl;

		} else { 
			printf("Falsche Eingabe!\n");
			abfrage = 0;
		}
	}

	return *zahl;
}

int ziffernAnzahlAusrechnen(int *zahl)
{
	printf("Die eingegebene Zahl ist %i\n", *zahl);
	int ziffernAnzahl = 0;
	int i;

	for(i=1; i <= *zahl; i=i*10)
	{
		ziffernAnzahl++;
	}
	
	printf("Die eingegebene Zahl besteht aus %i Ziffern.\n", ziffernAnzahl);

	return ziffernAnzahl;
}


int armstrongTest()
{	
	fflush(stdin);

	char eingabe;

	int zahl;
	int userZahl;


	do{	
		int i;
		int j;
		int speicher = 1;
		int summe = 0;

		system("clear");
		printf("//////////////////////////////////////////////////////\n");
		printf("/////////////////ARMSTRONGZAHLEN TEST/////////////////\n");
		printf("//////////////////////////////////////////////////////\n\n");

		benutzerEingabe(&zahl, &userZahl);

		int arrayDimensionierung = ziffernAnzahlAusrechnen(&zahl);
		int zahlenArray[arrayDimensionierung];


		for(i = 0; i<arrayDimensionierung; i++)
		{
			zahlenArray[i] = zahl%10;
			zahl = zahl / 10;

			printf("zahlenArray[%i]: %i\n", i, zahlenArray[i]);

			for(j=1; j <= arrayDimensionierung; j++)
			{
				speicher = speicher * zahlenArray[i];
				printf("Speicher: %i\n", speicher);
			}

			summe = summe + speicher;
			speicher = 1;

			printf("Summe: %i\n", summe);
		}

		printf("Ihre Eingabe: %i. Ausgabe des ARMSTRONGZAHLEN-ALGORITHMUS: %i\n", userZahl, summe );

		if(userZahl == summe)
		{
			printf("Ihre Zahl ist eine Armstrongzahl\n");
		} else {
			printf("Ihre Zahl ist keine Armstrongzahl\n");
		}

		fflush(stdin);
		printf("Nochmal berechnen? (y/n): ");
		scanf(" %c", &eingabe);
	} while(eingabe == 'y');


}

int main()
{
	armstrongTest();

	return 0;
}
