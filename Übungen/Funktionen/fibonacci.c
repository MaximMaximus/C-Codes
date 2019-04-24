#include <stdio.h>

int fibonacci(int n)
{
	if ( n == 0 ) {
		return 0;
	} else if ( n < 3 ) {
		return 1;
	} else if ( n > 0) {
		return fibonacci(n-1) + fibonacci(n - 2);
	}

}

int main() {
	int zahl = 0;
	fflush(stdin);
	scanf(" %d", &zahl);
	printf("Test: %d\n", fibonacci(zahl));
	return 0;	
}

/*
iterativ
unsigned int fibonacci(unsigned int zahl) {

    if (zahl == 0) { // Die Fibonacci-Zahl von null ist null

        return 0;

    } // else

    if (zahl == 1) { // Die Fibonacci-Zahl von eins ist eins

        return 1;

    } // else


    unsigned int ret;

    unsigned int h1 = 0;

    unsigned int h2 = 1;


    for (unsigned int i = 1; i < zahl; ++i) {

        // (Zwischen-)Ergebnis ist die Summe der zwei vorhergehenden Fibonacci-Zahlen.

        ret = h1 + h2; 

        // "vorherige zwei F.-Zahlen" um 1 "Stelle" der Reihe "weiter ruecken":

        h1 = h2;

        h2 = ret;

    }


    return ret;

}
*/