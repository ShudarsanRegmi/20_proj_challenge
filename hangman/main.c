#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "hangman.h"
#include "random.h"
#include "essentialfunc.h"

// constants
#define MAX 19

int main() {

    //Variables Initializaiton 
    int Score = 0;
    char * words[] = {
        "APPLE",
        "ORANGE",
        "BANANA",
        "STRAWBERRY",
        "GRAPE",
        "MELON",
        "WATERMELON",
        "PEACH",
        "NECTARINE",
        "PLUM",
        "CHERRY",
        "MANGO",
        "KIWI",
        "PINEAPPLE",
        "AVOCADO",
        "LEMON",
        "LIME",
        "ORANGE",
        "GRAPEFRUIT",
        "TRANGERINE",
        "CLEMENTINE"
    };

    /* char *words[50] = {"ram","shyam","\0"}; */

    int genedRanNo;

    /* hangman(7); */
    srand(time(NULL));
    /* printf("%d\n",genRandomNumber(MAX)); */

    int wannaPlay = 1;

    while (wannaPlay) {
		int foundIndices[10];
        int stage = 1;
        genedRanNo = genRandomNumber(MAX);
        char * chosenWord = words[genedRanNo]; // this is a string pointer; this is immutable
        printf("Chosen word: %s\n", chosenWord);
        /* char *chosenWord = "APPLEPPPOO"; // temporary */
        int lengthOfRandomWord = strlen(chosenWord);
        printf("Length of Random Word = %d\n", lengthOfRandomWord);
        int * mainIndices = malloc(sizeof(int) * lengthOfRandomWord);
        // initializing maijnIndices with -1
        for (int i = 0; i < lengthOfRandomWord; i++) {
            mainIndices[i] = -1;
        }
        int * lastIndex = malloc(sizeof(int));
        * lastIndex = 0;
        int noOfGusses = 0;
        while (1) {
            printf("\n---------------------BEGIN-FOR-A-WORD-------------------\n");
            char chosenChar = takeLetterInput();

            /* int x = checkChar(chosenWord,chosenChar); */
            int * x = checkChar(chosenChar, chosenWord);

            printf("Welcome back to main function \n: ");
				
            int numberOfMatches = x[0] - 1;
            if (numberOfMatches == 0) {
                printf("Incorrect guess!! \n");
                printf("Stage = %d\n", ++stage);
                /* hangman(7); */

            }
		hangman(stage);
            for (int i = 1; i <= numberOfMatches; i++) {
                printf("%d\t", x[i]);
            }
            printf("\n");

            addNewIndicesToMainIndices(mainIndices, lengthOfRandomWord, lastIndex, x, numberOfMatches);

            printf("\nIterating through the main list indices\n");
            for (int i = 0; i < lengthOfRandomWord; i++) {
                printf("%d\t", mainIndices[i]);
            }
            printf("\n");
            outputPrinter(chosenWord, mainIndices);


            if (checkCorrectGuess(mainIndices, lengthOfRandomWord)) {
                printf("Hurray!!!!!  the answer is correct.....\n");
                Score = Score + 10;
                gameOver(Score);
                break;

            }

            if (stage == 7) {
                Score = Score - 10;
                gameOver(Score);
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
			printf("Memory freed..");
		}
	}
// outer while loop close
}
