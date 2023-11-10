#include <stdio.h>

int hangman(int stage);

int main() {
	int stage = 3;
	hangman(stage);
}

/* /1* 🄰 *1/ */  
/* /1* 🄰 *1/ */
/* /1* 🄰🄱🄲🄳 *1/ */       

/* /1* █ ▀▀█ █▀▀▄ █▀▀ █▀▀▄ *1/ */ 
/* /1*    █▄▄█ █▀▀▄ █── █──█ *1/ */ 
/* ▀──▀ ▀▀▀─ ▀▀▀ ▀▀▀─ */
int hangman(int stage) {

	printf("head\n");
	printf("\t ______\n");
	printf("\t/      \\\n");
	printf("\t \\____/\n");
	if (stage == 1) {
		return 1;
	}
	printf("\t   |\n");
	
	if (stage >= 3) {
		printf("\t / | \\\n");
		printf("\t/  |  \\\n");
		if(stage == 3){
			return 3;
		}

	}else if(stage > 2) {
		printf("\t / |\n");
		printf("\t/  |\n");
	}else{
		printf("\t   |\n");
		printf("\t   |\n");
		return 2;
	}

	if(stage == 4) {
		return 5;
	}
	if(stage == 5) {
		return 5;
	}

	printf("left hand");
	if(stage == 6) {
		return 6;
	}

	printf("right leg");
	if(stage == 7) {
		return 7;
	}
	
	printf("Hanger");
	if(stage == 8) {
		return 8;
	}

}



