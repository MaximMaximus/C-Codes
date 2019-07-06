#include <stdio.h>

int main() {
	int i = 0;
	int j = 0;
	int x = 7;

	for(i = (x / 3); i < x; i+=2) {
		for(j = 1; j < x - i; j+=2) printf(" ");
		for(j = 1; j <= i; j++) printf("*");
		for(j = 1; j <= x - i; j++) printf(" ");
		for(j = 1; j <= i; j++) printf("*");
		printf("\n");
	}
	for(i = x; i >= 1; i--) {
		for(j = i; j < x; j++) printf(" ");
		for(j = 1; j <= (i*2) - 1; j++) printf("*");
		printf("\n");
	}
	
	return 0;
}
