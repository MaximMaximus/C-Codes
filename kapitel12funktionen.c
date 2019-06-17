#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Person {
	char name[10];
	int alter;
	struct Person *next;
} Person;

Person *create(char *person_name, int person_alter) {
	Person *neu = ( Person *)malloc( sizeof(Person) );

	if ( neu == NULL ) return NULL;

	strncpy( neu->name, person_name, 9 );
	neu->alter = person_alter;

	return neu;
}

void add_first(Person **anchor, Person *person) {
	person->next = *anchor;
	*anchor = person;
}

void add_last(Person **anchor, Person *person) {
		
	while(*anchor != NULL) {
		anchor = &(*anchor)->next;
	}
	*anchor = person;
	//printf("&anchor %d\n", &anchor);
	//printf("anchor %d\n", anchor);
	//printf("*anchor %d\n", *anchor);
	//printf("**anchor %d\n", **anchor);
	//printf("&(*anchor) %d\n", &(*anchor)->next);
	person->next = NULL;
}

void print_all(Person *anchor) {
	printf("\nPrint list: \n");
	while(anchor != NULL) {
		printf("%-10s (%d Jahre)\n", anchor->name, anchor->alter);
		anchor = anchor->next;
	}
}

int compare(Person *p1, Person *p2) {
	int stringvergleich = strcmp(p1->name, p2->name);
	if(stringvergleich != 0) {
		return stringvergleich;
	}

	if(p1->alter > p2->alter) return 1;
	else if(p1->alter < p2->alter) return -1;
	else return 0;
	// oder return p1->alter - p2->alter;
}

void compare_all(Person **anchor) {
	Person *second = (Person *)malloc(sizeof(Person));
	int i = 0;
	printf("\nCompare all: \n");
	while(*anchor != NULL) {
		i++;
		printf("%d. Name: %s\n", i, (*anchor)->name);
		second = (*anchor)->next;
		while(second != NULL) {
			printf("%s (%d Jahre) und %s (%d Jahre): %d\n", (*anchor)->name, (*anchor)->alter, second->name, second->alter, compare(*anchor, second));
			second = second->next;
		}
		printf("\n");
		anchor = &(*anchor)->next;
	}
}

/*
void dublicate_delete(Person *anchor) {
	Person *first = (Person *)malloc(sizeof(Person));
	Person *second = (Person *)malloc(sizeof(Person));
	Person *temp = (Person *)malloc(sizeof(Person));
	first = anchor;
	printf("Dublicate delete: \n");
	while(first != NULL && first->next != NULL) {
		second = first->next;
		while(second != NULL) {
			if(compare(first->name, second->name) == 0) {
				temp = first->next->next;
				free(first->next);
				first->next = temp;
			} else {
				printf("%s (%d Jahre) und %s (%d Jahre): %d\n", first->name, first->alter, second->name, second->alter, compare(first->name, second->name));
				second = second->next;
			}
		}
		first = first->next;
		printf("\n");
	}
}
*/

void dublicate_delete(Person **anchor) {
	printf("\nDelete dublicate! \n");
	Person *second = *anchor;
	while(*anchor != NULL) {
		second = (*anchor)->next;
		while(second != NULL) {
			if(compare(*anchor, second) == 0) {
				Person *deleted = *anchor;
				*anchor = (*anchor)->next;
				free(deleted);
			}
			second = second->next;
		}
		anchor = &(*anchor)->next;
	}
}

Person *delete(Person **anchor, Person *to_delete) {
	printf("\nDelete: %s\n", to_delete->name);
	while(*anchor != NULL) {
		if( compare(*anchor, to_delete) == 0 ) {
			Person *deleted = *anchor;
			*anchor = (*anchor)->next;
			return deleted;
		}
		anchor = &(*anchor)->next;
	}
	return NULL;
}

void sort(Person *anchor) {
	Person *first = (Person *)malloc(sizeof(Person));
	Person *second = (Person *)malloc(sizeof(Person));
	Person *temp = (Person *)malloc(sizeof(Person));
	first = anchor;
	
	printf("\nSort! \n");
	while(first != NULL) {
		second = first->next;
		while(second != NULL) {
			if(strcmp(first->name, second->name) > 0) {
				temp->alter = second->alter;
				second->alter = first->alter;
				first->alter = temp->alter;
				strcpy(temp->name, second->name);
				strcpy(second->name, first->name);
				strcpy(first->name, temp->name); 
				//printf("treffer\n");
			}
			second = second->next;
			//printf("test\n");
		}
		first = first->next;
	}
}

void sort2(Person **anchor) {
	printf("\nSort! \n");
	Person *second = *anchor;
	while(*anchor != NULL) {
		printf("while 1 %s\n", (*anchor)->name);
		second = (*anchor)->next;
		while(second != NULL) {
			printf("while2 %s\n", (*anchor)->name);
			if(compare(*anchor, second) > 0) {
				printf("compare anchor %s\n", (*anchor)->name);
				printf("compare second %s\n", second->name);
				Person *temp = *anchor;
				*anchor = second;
				second = temp;
			}
			second = second->next;
		}
		anchor = &(*anchor)->next;
	}
}

void sort3(Person **anchor) {
	printf("\nSort!\n");
	int done = 0;

	if(*anchor == NULL || (*anchor)->next == NULL) return;

	while(!done) {
		Person **originalCopy = anchor;

		Person *start = *anchor;
		Person *second = (*anchor)->next;

		done = 1;

		while(second) {
			int cmp = strcmp(start->name, second->name);

			if(cmp > 0) {
				start->next = second->next; // 1 zeig auf 3
				second->next = start; // 2 zeigt auf 1
				*originalCopy = second; // 1original = 2

				done = 0;
			}
			originalCopy = &start->next; // 1original Adresse ist Adresse von 3
			start = second; // 1 = 2
			second = second->next; // 2 = 2
		}
	}
}

void add_sorted(Person **anchor, Person *person) {
	printf("\nAdd sorted Name: %s\n", person->name);
	while(*anchor != NULL && compare(*anchor, person) < 0) {
		anchor = &(*anchor)->next;
	}
	person->next = *anchor;
	*anchor = person;
}

void reverse(Person **anchor) {
	printf("\nReverse list!\n");
	Person *last = NULL;
	while(*anchor != NULL) {
		Person *temp = *anchor;
		*anchor = (*anchor)->next;
		temp->next = last;
		last = temp;
	}
	*anchor = last;
}

int main() {
	Person *liste = NULL;

	add_first( &liste, create("Max", 18) );
	add_first( &liste, create("Lisa", 21) );
	add_first( &liste, create("Fritz", 19) );
	add_first( &liste, create("Fritz", 19) );

	add_last( &liste, create("Anna", 30) );
	add_last( &liste, create("Mali", 28) );

	print_all(liste);
	//compare_all(&liste);

	delete( &liste, create("Lisa", 21) );
	print_all(liste);

	dublicate_delete(&liste);
	print_all(liste);

	sort3(&liste);
	print_all(liste);

	add_sorted( &liste, create("xxx", 18));
	print_all(liste);

	reverse(&liste);
	print_all(liste);

	return 0;
}
