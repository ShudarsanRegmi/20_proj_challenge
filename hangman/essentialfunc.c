#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "essentialfunc.h"
#include "hangman.h"

char takeLetterInput() {	
	char mychar;
	printf("\nGuess a letter:  ");
	scanf("%c",&mychar);	
	getchar();
	/* printf("Captured Character: %c",mychar); */
	return mychar;
}

int genRandomNumber(int max) {
	return rand() % max;
	
}

int *checkChar(char chosenChar, char *word) {
	/* int foundIndices[10]; */ // don't do this becuase after this function returns this variable is deallocated
	 int *foundIndices = malloc(sizeof(int)*10); // will see if i can use strlen(word) or not
	int size= 1;

	/* printf("\n----\n"); */
	/* printf("\nchosen char = %c\n",chosenChar); */
	/* printf("word = %s\n",word); */
	/* printf("The length of word is: %ld\n",strlen(word)); */


	for (int i=0;i<strlen(word);i++) {

		// I need to check if the word was already entered
			

		if(word[i] == chosenChar) {
			/* printf("matched Character: %c\n",chosenChar); */
			/* printf("Found index:%d\n ",i); */
			foundIndices[size++] = i;
	}

}

	foundIndices[0] = size;
	// printing the listing array
	/* printf("\n--------printing the listing array------\n"); */

	/* for (int i =0; i<size; i++) { */
	/* 	printf("%d\n",foundIndices[i]); */	
	/* } */
	return foundIndices;


}




void addNewIndicesToMainIndices (int *mainIndices, int lengthofRandomWord, int *lastIndex, int *x , int numberofMatches) {
	/* printf("Hello, World\n"); */

	/* printf("Number of matches = %d\n",numberofMatches); */
	/* printf("Length of Random Word = %d\n",lengthofRandomWord); */
	/* printf("The last index of main array is: %d\n",*lastIndex); */
	/* printf("HERE..."); */

		/* for (int i=1; i<=numberofMatches;i++) { */
		/* 	printf("%d\t",x[i]); */
		/* } */
		for (int i=0;i<numberofMatches;i++) {
			mainIndices[(*lastIndex)++] = x[i+1];
		}


}


void outputPrinter(const char *word, int indices[]) {

/* printf("\nExecuting.....\n "); */
	
printf("\n-----------------------------------\n\n");
	int outerbreak;
	for(int i=0; i< strlen(word); i++) {
		outerbreak = 0;
	
		for (int j=0;j<strlen(word);j++) {
			if(i == indices[j]) {
				printf(" %c ",word[i]);
				outerbreak = 1;

			}
		}
		if(outerbreak == 1) continue;
		printf(" _ ");

	}
printf("\n-----------------------------------\n");

// duplicate entries can be removed from a list..
// removing duplicate netry from the arrray is a good idea.. 
	
	/* printf("\nExecuting.....\n "); */
}


int checkCorrectGuess(int *listings,int length) {

	/* printf("Checking correctness of your answer...............\n"); */
	for (int i = 0; i<length; i++) {

	if(listings[i] == -1) {
		/* printf("Answer not correct"); */
		return 0;
	}else{
		if(i == length-1) {
			/* printf("Answer is correct: "); */
			return 1;
		}
	}

	}


}


void gameOver(int Score) {
	printf("\n-----------------------------------------------------------\n");
	printf("Your score is: %d\n",Score);
	printf("-----------------------------------------------------------\n");

}

int wannaPlayAgain() {
		char pa;
		printf("Do you want to play again? ");
		scanf("%c",&pa);
		getchar();
		pa = toupper(pa);
		if(pa == 'Y') {
			/* printf("Play again"); */
			return 1;
		}else{
			/* printf("Don't wanna play.. \n"); */
			return 0;
		}

	}

int isalreadytaken(const char chosenchar, char *entered_char, int chosen_chars_length) {
	// check if chosenchar is there in entered_char array or not
	
	for (int i=0;i<chosen_chars_length;i++) {
		if(chosenchar == entered_char[i]) {
			printf("Letter already entered..\n");
			return 1;
		}
	} 
	/* printf("Letter not entered..\n"); */
	return 0;
}

























