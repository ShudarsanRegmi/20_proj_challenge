#ifndef LIBRARY_H
#include <stdio.h>
#define LIBRARY_H
#endif

struct Players {
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
