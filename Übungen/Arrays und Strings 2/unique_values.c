#include <stdio.h>

int has_unique_values(int a[], int l) {
	int i = 0;
	int j = 0;
	for ( i = 0; i < l; i++ ) {
		for ( j = 1; j < l-i; j++ ) {
			printf("i %d wert %d und j: %d wert %d\n", i, a[i], j, a[j+i]);
			if ( a[i] == a[j+i] ) {
				return 0;
				break;
			}
		}
	}
}

int main() {
	int unique[] = { 3, -17, 9, 0, 8, 42 };
	int not_unique[] = { 3, -17, 9, 0, 9, 3, 42, 4 };
	if ( has_unique_values(unique, 6) ) printf("passt!\n");
	if ( !has_unique_values(not_unique, 8) ) printf("passt auch!\n");

	return 0;
}
