

#ifndef RANDOM_NUMBER_GENERATOR
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define RANDOM_NUMBER_GENERATOR
int genRandomNumber(int max);
#endif


int genRandomNumber(int max) {
	return rand() % max;
	
}
