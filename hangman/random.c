#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int genRandomNumber(int max);

int main() {
	srand(time(NULL));	
	int max = 50;
}

int genRandomNumber(int max) {
	return rand() % max;
	
}
