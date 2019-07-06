#include <stdio.h>

int main() {
	int i = 0;
	int j = 0;
	int x = 8;
	int star = 0;
	for(i = 1; i <= x - 3; i++) {
		for(j = 0; j < x - 3 - i; j++) printf(" ");
		while(star != (i*2 - 1)) {
			printf("*");
			star++;
		}
		star = 0;
		printf("\n");
	}
	for(i = 3; i <= x - 3; i++) {
		for(j = 0; j < x - 3 - i; j++) printf(" ");
		while(star != (i*2 - 1)) {
			printf("*");
			star++;
		}
		star = 0;
		printf("\n");
	}

	
	for(i = 3; i <= x; i++) {
		if(i <= 5) {
			for(j = 0; j < 5 - i; j++) {
				printf(" ");
			}
			while(star != (2*i - 1)) {
				printf("*");
				star++;
			}
			star = 0;
			printf("\n");
		} else {
			for(j = 0; j < 9; j++) {
				if((int)(j/3) == 1) printf("*");
				else printf(" ");
			}
			printf("\n");
		}
	}
			

	return 0;
}
