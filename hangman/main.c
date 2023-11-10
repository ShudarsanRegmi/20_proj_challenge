#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "hangman.h"
#include "random.h"

// constants
#define MAX 50

int main() {
	hangman(7);	
	srand(time(NULL));	
	printf("%d\n",genRandomNumber(MAX));
	return 0;
}
