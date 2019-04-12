#include <stdio.h>

int is_prime_number(int zahl) {

	int i = 0;

	for ( i = 3; i <= zahl; i++ ) {
		if ( zahl % i == 0 && zahl != i ) {
    		break;
    	} else if ( zahl % i == 0 && zahl == i ) {
           return 1;
    	}
	}
	return 0;
}

int print_prime_factors(int zahl) {

    int speicher = zahl;
	int teiler = 2;
   	int i = 0;

    printf("%d =", zahl);
    while (i != 1) {

        while ( speicher % teiler != 0 ) 
        {
            teiler++;
        }
        
        while ( speicher % teiler == 0 ) 
        {
            speicher = speicher / teiler;
            printf(" %d ", teiler);
            if ( speicher >= teiler ) {
                printf("*");
            }
        }

        if ( speicher < teiler )
        {
            i = 1;
        }
        else 
        {
            i = 0;
        }
    }
}

int main() {
	int uservalue = 0;

	printf("Primzahltest\n");
	printf("Geben Sie eine Zahl ein: \n");
	fflush(stdin);
	scanf("%d", &uservalue);

	printf("Ihre Zahl: %d\n", uservalue);

	if ( is_prime_number(uservalue) ) {
		printf("Primzahl!\n");
		printf("Teiler von %d ist %d", uservalue, uservalue);
	} else {
		printf("Keine Primzahl!\n");
		print_prime_factors(uservalue);
	}

	return 0;
}
