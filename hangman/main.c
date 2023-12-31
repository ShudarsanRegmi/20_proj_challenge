#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "hangman.h"
#include "essentialfunc.h"
// constants
#define MAX 19

int main() {

    //Variables Initializaiton 
    int Score = 0;
    char * words[] = { "APPLE", "ORANGE", "BANANA", "STRAWBERRY", "GRAPE", "MELON", "WATERMELON", "PEACH", "NECTARINE", "PLUM", "CHERRY", "MANGO", "KIWI", "PINEAPPLE", "AVOCADO", "LEMON", "LIME", "ORANGE", "GRAPEFRUIT", "TRANGERINE", "CLEMENTINE" };	



    //const char words[] = animals[];
    int genedRanNo;

    srand(time(NULL));
    /* printf("%d\n",genRandomNumber(MAX)); */

    int wannaPlay = 1;

	printf("Welcome to Hangman!!\n");
	printf("The rules are simple: I will think of a word, and you will try to guess it.");
	printf("You have 6 incorrect guesses before you lose.\n");
	printf("--------------------------------------------------\n");
	int firstTime = 1;
    while (wannaPlay) {
		int foundIndices[10];
        int stage = 0;
		
		/* char enteredCharacter[25]; */
		/* char *ptr = &enteredCharacter; */
		/* int *indexOfLastEnteredCharacter = 0; */

		char *entered_char = malloc(sizeof(char)*26);

        genedRanNo = genRandomNumber(MAX);
        char * chosenWord = words[genedRanNo]; // this is a string pointer; this is immutable
        /* char *chosenWord = "WATERMELON"; // temporary */
        /* printf("Chosen word: %s\n", chosenWord); */
        int lengthOfRandomWord = strlen(chosenWord);
        /* printf("Length of Random Word = %d\n", lengthOfRandomWord); */
        int * mainIndices = malloc(sizeof(int) * lengthOfRandomWord);
        // initializing maijnIndices with -1
        for (int i = 0; i < lengthOfRandomWord; i++) {
            mainIndices[i] = -1;
        }
        int * lastIndex = malloc(sizeof(int));
        * lastIndex = 0;
        int noOfGusses = 0;


		if(!firstTime) {
			printf("\033[H\033[J");
			firstTime = 0;
		}


		hangman(stage);
		outputPrinter(chosenWord, mainIndices);
		int loopcount = 0;
		int chosen_chars_length = 0;
        while (1) {
		char chosenChar;
            /* printf("\n---------------------BEGIN-FOR-A-WORD-------------------\n"); */
			do {
				chosenChar = takeLetterInput();

			}while(isalreadytaken(chosenChar,entered_char, chosen_chars_length));
			loopcount++;	


			if(!isalreadytaken(chosenChar,entered_char,chosen_chars_length)) {
				entered_char[chosen_chars_length] = chosenChar;
				chosen_chars_length++;
			}

            /* int x = checkChar(chosenWord,chosenChar); */

			// check only if chosen char is being entered for the first time
				
            int * x = checkChar(chosenChar, chosenWord);

			/* printf("printing foundIndices: \n"); */
			/* for(int i=0;i<x[0];i++) { */
			/* 	printf("%d\t",x[i]); */
			/* } */
			/* printf("\n"); */

			// foundIndices is returned.. 
            /* printf("Welcome back to main function \n: "); */
				
            int numberOfMatches = x[0] - 1;
            if (numberOfMatches == 0) {
                /* printf("Incorrect guess!! \n"); */
                /* printf("Stage = %d\n", stage++); */
				stage++;
                /* hangman(7); */

            }

            /* for (int i = 1; i <= numberOfMatches; i++) { */
            /*     printf("%d\t", x[i]); */
            /* } */
            /* printf("\n"); */

            addNewIndicesToMainIndices(mainIndices, lengthOfRandomWord, lastIndex, x, numberOfMatches);

			/* printf("After adding new indices \n"); */
			/* for(int i=0;i<lengthOfRandomWord;i++) { */
			/* 	printf("%d\t",mainIndices[i]); */
			/* } */
			printf("\n");

            /* printf("\nIterating through the main list indices\n"); */

            /* for (int i = 0; i < lengthOfRandomWord; i++) { */
            /*     printf("%d\t", mainIndices[i]); */
            /* } */

            /* printf("\n"); */


			// not sure if ths works in windows 
			printf("\033[H\033[J");
			hangman(stage);
			outputPrinter(chosenWord, mainIndices);


            if (checkCorrectGuess(mainIndices, lengthOfRandomWord)) {
				printf("\n-----------------------------------\n\n");
                printf("Hurray!!!!!  the answer is correct !!!\n");
				printf("\n-----------------------------------\n\n");

                Score = Score + 10;
                gameOver(Score);
                break;

            }

            if (stage == 7) {
                Score = Score - 10;
                gameOver(Score);
				printf("The Correct Answer was: %s\n",chosenWord);
                break;
			}


		}
	// inner while loop close

	
		if (!wannaPlayAgain()) {
			gameOver(Score);
			break;
		}else{
			free(mainIndices);
			free(lastIndex);
			/* printf("Memory freed.."); */
		}
	}
// outer while loop close
}
