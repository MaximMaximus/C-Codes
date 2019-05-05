#include <stdio.h>
#include <string.h>

char* suche (char *str, char*such, unsigned int n) {

	/*
	char temp[100];
	strcpy(temp, "");
	printf ("%s\n", strstr(str, such));
	strcat(temp, strstr(str, such));
	printf("Temp: %s\n", temp);
	*/

	char *res = str;
	int i = 0;
	for( i = 0; i < n; i++) {
		res = strstr(res, such);
		if(i != n-1) {
			res += 2;
		}
	}
	return res;
}


int main() {


	printf("%s\n", suche("dreierleieierei", "ei", 1) ); // ergibt: eierleieierei 
	printf("%s\n", suche("dreierleieierei", "ei", 3) ); // ergibt: eierei 
	printf("%s\n", suche("dreierleieierei", "ei", 4) ); // ergibt: ei 
	printf("%s\n", suche("barbara macht barbarei", "arba", 2) ); // ergibt: arbarei 
	suche("dreierleieierei", "ei", 1);
	suche("barbara macht barbarei", "asd", 1);


	return 0;
}

