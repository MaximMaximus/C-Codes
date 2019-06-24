#include <stdio.h>
#include <stdlib.h>

enum Bool { FALSE, TRUE };

typedef struct Bullet {
	float x;
	float y;
	enum Bool dead;
	struct Bullet *next;
	struct Bullet *previous;
} Bullet;

Bullet *firstBullet = NULL;
Bullet *lastBullet = NULL;

struct Bullet *newBullet(float x, float y) {
	Bullet *new = (Bullet*)malloc(sizeof(Bullet));
	if(firstBullet == NULL) {
		firstBullet = new;
		lastBullet = firstBullet;
		lastBullet->next = NULL;
		lastBullet->previous = NULL;
	} else {
		lastBullet->next = new;
		lastBullet->next->previous = lastBullet;
		lastBullet = lastBullet->next;
		lastBullet->next = NULL;
	}
	lastBullet->x = x;
	lastBullet->y = y;
	lastBullet->dead = FALSE;

	return lastBullet;
}

void updateBullet() {
	//Bullet *thisBullet = (Bullet*)malloc(sizeof(Bullet));
	Bullet *thisBullet = firstBullet;

	while(thisBullet != NULL) {
		thisBullet->y -= 2;
		if(thisBullet->y < 0) {
			thisBullet->dead = TRUE;
		}
		thisBullet = thisBullet->next;
	}
}

void renderBuellet() {
	Bullet *thisBullet = firstBullet;
	Bullet *deadBullet = NULL;

	while(thisBullet != NULL) {
		if(thisBullet->dead) {
			deadBullet = thisBullet;
			thisBullet = thisBullet->next;

			if(firstBullet == deadBullet) {
				firstBullet = thisBullet;
				if(thisBullet != NULL) {
					thisBullet->previous = NULL;
				}
			} else {
				deadBullet->previous->next = thisBullet;
				if(thisBullet != NULL) {
					thisBullet->previous = deadBullet->previous;
				}
			}
			if(lastBullet == deadBullet) {
				lastBullet = deadBullet->previous;
			}
			free(deadBullet);
		} else {
			// drawing section here
			thisBullet = thisBullet->next;
		}
	}
}

void deleteAllBullet() {
	Bullet *thisBullet = firstBullet;
	Bullet *deadBullet = NULL;

	while(thisBullet != NULL) {
		deadBullet = thisBullet;
		thisBullet = thisBullet->next;
		free(deadBullet);
	}
	firstBullet = NULL;
	lastBullet = NULL;
}

int main() {

	return 0;
}
