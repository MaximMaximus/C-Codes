#include <stdio.h>
#include <math.h>

int main() {
	int i = 0;
	int j = 0;
	int x = 4;
	
	for(i = 0; i < x; i++) {
		for(j = 0; j < pow(2, i); j++) {
			printf("*");
		}
		printf("\n");
	} 
	
	return 0;
}
