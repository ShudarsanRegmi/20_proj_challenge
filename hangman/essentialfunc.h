#ifndef ESSENTIAL_FUNC_H
#define ESSENTIAL_FUNC_H

int genRandomNumber(int max);
char takeLetterInput(void);
int *checkChar(char chosenChar, char *word);

void addNewIndicesToMainIndices (int *mainIndices, int lengthofRandomWord, int *lastIndex, int *x , int numberofMatches);

void outputPrinter(const char *word, int indices[]);
int checkCorrectGuess(int *listings,int length);
void gameOver(int Score);
int wannaPlayAgain(void);
int isalreadytaken(const char chosenchar, char *entered_char, int chosen_chars_length);
#endif
