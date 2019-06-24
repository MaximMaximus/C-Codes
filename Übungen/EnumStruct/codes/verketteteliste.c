#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <malloc.h>

char end[] = "?!.";

typedef struct node{
	char word[16];
	struct node *next;
} TCell;

int main(void) {
	TCell *head, *man, *q;
	char currentWord[16], c;
	int k;
	head = NULL; currentWord[0] = '\0'; k = 0;
	printf("Geben Sie den Satz ein:\n");

	do {
		scanf("%c", &c);
		if(!isalpha(c)){
			if(k){
				printf("test\n");
				q = (TCell*) malloc(sizeof(TCell));
				strcpy(q->word, currentWord);
				q->next = NULL;
				k = 0;
			if(head == NULL) { head = q; man = q; }
			else { man->next = q; man = q; }
			}
		}
		else { currentWord[k++]=c; currentWord[k]='\0';}
	} while(!strrchr(end, c));

	printf("\nDie Woerter im Satz sind:");
	while(head) {
		printf("\n%s", head->word);
		man = head;
		head = head->next;
		free(man);
	}

	return 0;
}
