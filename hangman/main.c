#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "hangman.h"
#include "random.h"
#include "essentialfunc.h"

// constants
#define MAX 19

int main() {

	//Variables Initializaiton 
	int Score = 0;	
	char *words[] = { "APPLE", "ORANGE", "BANANA", "STRAWBERRY", "GRAPE", "MELON", "WATERMELON", "PEACH", "NECTARINE", "PLUM", "CHERRY", "MANGO", "KIWI", "PINEAPPLE", "AVOCADO", "LEMON", "LIME", "ORANGE", "GRAPEFRUIT", "TRANGERINE", "CLEMENTINE"};


	char *dynamicArray;
	/* char *words[50] = {"ram","shyam","\0"}; */

	int genedRanNo;

	/* hangman(7); */	
	srand(time(NULL));	
	/* printf("%d\n",genRandomNumber(MAX)); */
	
	int wannaPlay = 1;
	int foundIndices[10];
	foundIndices[0] = 1;
	foundIndices[1] = 2;
	foundIndices[2] = 3;
	foundIndices[3] = 4;

	while (wannaPlay) {
		genedRanNo = genRandomNumber(MAX);
		// char *chosenWord = words[genedRanNo]; // this is a string pointer; this is immutable
		char *chosenWord = "APPLEPPPOO"; // temporary
		int lengthOfRandomWord = strlen(chosenWord);
		printf("Length of Random Word = %d\n",lengthOfRandomWord);
		int *mainIndices = malloc(sizeof(int) * lengthOfRandomWord);
		int *lastIndex = malloc(sizeof(int));
		*lastIndex = 0;
		
		while(1) {
			printf("\n---------------------BEGIN-FOR-A-WORD-------------------\n");
			char chosenChar = takeLetterInput();

			/* int x = checkChar(chosenWord,chosenChar); */
			int *x = checkChar(chosenChar, chosenWord);

			printf("Welcome back to main function \n: ");
		
			int numberOfMatches = x[0]-1;
			if(numberOfMatches == 1) printf("nothing matched");	
			for (int i=1; i<=numberOfMatches;i++) {
				printf("%d\t",x[i]);
			}
			printf("\n");

			addNewIndicesToMainIndices(mainIndices, lengthOfRandomWord, lastIndex, x , numberOfMatches );


			printf("\nIterating through the main list indices\n");
			for(int i=0;i<lengthOfRandomWord; i++) {
				printf("%d\t",mainIndices[i]);
			}	
			printf("\n");
		}	
		// now i need to get the list which holds all the indeces that has been found out
			
		
	}
	
	return 0;
}
