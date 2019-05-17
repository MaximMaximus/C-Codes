#include <stdio.h>

void adresse_zerlegen (char *original, char *street, int *nummer) {
	int i = 0;
	while(!(original[i] >= '0' && original[i] <= '9')) {
		street[i] = original[i];
	i++;
	}
	street[i] = '\0';

	while(original[i] >= '0' && original[i] <= '9') {
		*nummer = *nummer * 10 + original[i] - '0';
		i++;
	}
}

int main() {
	char adresse_original[100] = "Alan-Turin-Allee 193, 4. Stock";
	char strasse[100];
	int hausnr;

	adresse_zerlegen(adresse_original, strasse, &hausnr);

	printf("Strassenname : %s\n", strasse);
	printf("Hausnummer   : %d\n", hausnr);

	return 0;
}
