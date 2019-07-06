#include <stdio.h>

int main() {
	int i = 0;
	int j = 0;
	int x = 7;
	int star = 0;
	
	for(i = 1; i <= x; i++) {
		for(j = 0; j < x - i; j++) printf(" ");
		if(i < x) {
			while(star != (i*2 - 1)) {
					if( star == 0 || star == (i*2-1)-1) printf("*");
				else printf(" ");
				star++;
			}
			star = 0;
			printf("\n");
		} else {
			for(j = 0; j < x*2-1; j++) printf("*");
		}
	}
	return 0;
}
