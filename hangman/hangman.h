#include <stdio.h>

#ifndef HANGMAN
#define HANGMAN
int hangman(int stage);
#endif


int hangman(int stage) {

	if(stage == 7) {
		printf("------------\n");
		printf("\t   |\n");
		printf("\t   |\n");
	}

	printf("\t ______\n");
	if(stage==0) {
		return 0;
	}
	printf("\t/      \\\n");
	printf("\t \\____/\n");
	if (stage == 1) {
		return 1;
	}

	printf("\t   |\n");
	if (stage == 2) {
		printf("\t   |\n");
		printf("\t   |\n");
		printf("\t   |\n");
	}else {
		if (stage == 3)	 {
			printf("\t / |\n");
			printf("\t/  |\n");
			printf("\t   |\n");
			return 3;
		}

		if (stage >= 4) {
			printf("\t / | \\\n");
			printf("\t/  |  \\\n");
			printf("\t   |     \n");
			if (stage == 4) {
				return 4;
			}
		}
	}
	if(stage == 5) {
		printf("\t  /\n");
		printf("\t /\n");
		printf("\t/\n");
		return 5;
	}

	if (stage > 5) {
		printf("\t  / \\\n");
		printf("\t /   \\\n");
		printf("\t/     \\\n");
		if(stage == 6) {
			return 6;	
		}
	}
	
	if(stage == 7) {
		printf("\n\n------------------------\n");
		printf("Hanged");
		return 7;
	}
}
