#include <stdio.h>

int main() {
	int i = 0;
	int j = 0;
	int x = 7;
	
	for(i = 0; i < x; i++) {
		for(j = 0; j < x + i; j++) {
			if(j < i) printf(" ");
			else printf("*");
		}
		printf("\n");
	}

	return 0;
}
