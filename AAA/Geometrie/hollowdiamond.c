#include <stdio.h>

int main() {
	int i = 0;
	int j = 0;
	int x = 8;
	int star = 0;	

	for(i = 1; i <= x; i++) {
		for(j = 0; j < x - i; j++) {
			printf(" ");
		}
		while(star != (i*2 - 1)) {
			if(star == 0 || star + 1 == (i*2 - 1)) printf("*");
			else printf(" ");
			star++;		
		}
		star = 0;
		printf("\n");
	}
	for(i = x - 1; i >= 1; i--) {
		for(j = 0; j < x - i; j++) {
			printf(" ");
		}
		while(star != (i*2 - 1)) {
			if(star == 0 || star + 1 == (i*2 - 1)) printf("*");
			else printf(" ");
			star++;		
		}
		star = 0;
		printf("\n");
	}

	return 0;
}
