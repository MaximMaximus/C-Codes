void betrag(int *zahl) {
	if ( *zahl < 0 ) {
		*zahl *= -1;
	}
}

void sort(int *a, int *b) {
	int speicher = 0;

	speicher = *b;
	*b = *a;
	*a = speicher;
}

void runde_summe(int *a, int *b, int *c, int *summe) {

	betrag(a);
	betrag(b);
	betrag(c);

	while ( *a > *b || *b > *c ) {

		if ( *a > *c ) {
			sort(a, c);
		}

		if ( *a > *b ) {
			sort(a, b);
		}

		if ( *b > *c ) {
			sort(b, c);
		}
	}

	*summe = *a + *b + *c;

	if ( *summe < 10 ) *summe = 10;
	else if ( *summe % 10 < 5 ) *summe = *summe /10 * 10;
	else if ( *summe % 10 > 5 ) *summe = *summe /10 * 10 + 10;
}
