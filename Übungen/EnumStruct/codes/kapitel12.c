#include <stdio.h>

typedef struct Person {
	char name[10];
	int alter;
	struct Person *next;
} Person;

int main() {
	Person *anker = NULL;

	anker = ( Person *)malloc( sizeof(Person) );
	anker->alter = 18;
	strcpy(anker->name, "Max");
	anker->next = NULL;

	Person *p2 = ( Person *)malloc( sizeof(Person) );
	p2->alter = 21;
	strcpy(p2->name, "Lisa");
	p2->next = NULL;
	anker->next = p2;

	Person *p3 = ( Person *)malloc(sizeof(Person) );
	p3->alter = 19;
	strcpy(p3->name, "Fritz");
	p3->next = NULL;
	p2->next = p3;

	Person *element = anker;
	while( element != NULL ) {
		printf("%-10s (%d Jahre)\n", element->name, element->alter);
		element = element->next;
	}

	return 0;
}
