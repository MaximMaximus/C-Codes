#include <stdio.h>

int abweichung(char *string1, char *string2) {
	int i = 0;
	int stelle = 0;
	for ( i = 0; string1[i] != NULL; i++ ) {
		if( string1[i] == string2[i] ) {
			stelle++;
		} else {
			break;
		}
	}
	return stelle;
}

int main() {
	char s1[] = "abcdefghijk";
	char s2[] = "abcef";

	char s3[] = "abcdefghijk";
	char s4[] = "bcdf";

	printf("%d", abweichung(s1, s2));
	printf("%d", abweichung(s3, s4));

	return 0;
}
