#ifndef LIBRARY_H
#include <stdio.h>
#include <stdlib.h>
#define LIBRARY_H
#endif

struct Players {
	int id;
	char name[20];
	char color;
	int pos;
};

struct Snakes {
	int from;
	int to;
};

struct Ladders {
	int from;
	int to;
};

// functions
//
//
// the seed for random function

int roll_dice() {
	return (rand() % 6)+1;	
}

int move_gotti(struct Players p,  int step) {
	printf("Turn: %s\n",p.name);
	printf("Current Position: %d\n",*cur_post);
	printf("Step: %d\n",step);
}

