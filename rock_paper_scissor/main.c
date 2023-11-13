#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int checkWinner(int user, int computer) {

	// 0 --> rock
	// 1 --> paper
	// 2 --> Scissor
	
	if(user == computer) {
		return -1; //  -1 signifies tie
	}
    // for RS -> R is the winner
	if ((user == 0 && computer == 2) || (user == 2 && computer == 0) ) {
		// rock is winner

		if(user == 0) {
			return 0;
			// user is winner
		}else{
			// computer is winner
			return 1;

		}

		// RP --> paper winner
	}else if ((user == 0 && computer == 1) || (user == 1 && computer == 0)){
        // paper is winner
        if(user == 1) {
		    return 0;
			// user is winner
		}else{
			// computer is winner
			return 1;

		}
      // PS --> Scissor is winner  
	}else if ((user == 1 && computer == 2) || (user == 2 && computer == 1)){
        // scissor is winner
        if(user == 2) {
		    printf("user is winner");
			// user is winner
			return 0;
		}else{
			// computer is winner
			return 1;
		}
	    
	    
	}else{
	    printf("Unhandeled Exception");
	    return -1;
	}


}

char getchoicestr(int choice) {
	if (choice == 0)
		return 'R';
	else if (choice == 1)
		return 'P';
	else if (choice == 2)
		return 'S';
	else
		return 'X';
}

void displayscore(int userscore, int computerscore) {
	printf("--------SCORE-------------------\n");
	printf("You: %d\n",userscore);
	printf("Computer: %d\n",computerscore);
	printf("--------------------------------\n");
}
int main() {
	// rock = 0
	int userscore = 0;
	int computerscore = 0;
	int userchoice;
	int winner;
	int computerchoice;
	char user_choice_str;
	char comp_choice_str;
	
	srand(time(NULL));

	while(1) {
	// main game loop
		// computer generate
		computerchoice = rand()%3;
		
		// clear the terminal screen

		// keep on asking until the userchoce is equal to either of 1 2 or 3
		do {
			printf("\nPress 1 for Rock \nPress 2 for Paper \nPress 3 for Scissor\nPress 4 to exit\n: ");
			scanf("%d",&userchoice);
			printf("\033[H\033[J");
			
		} while (!(userchoice == 1 || userchoice == 2 || userchoice == 3 || userchoice == 4));

		if(userchoice== 4) {
			printf("Bye!!\n");
			return 0;
		}
		
		user_choice_str = getchoicestr(userchoice-1);
		comp_choice_str = getchoicestr(computerchoice);

		printf("You: %c\n",user_choice_str);
		printf("Computer: %c\n",comp_choice_str);
	
		winner = checkWinner(userchoice-1, computerchoice);
	//int winner = 0;

		if(winner == 0) {
			printf("--------------------------------\n");
			printf("You Won!!\n");
			printf("--------------------------------\n");
			userscore++;
		}else if(winner == 1) {
			printf("--------------------------------\n");
			printf("Computer Won!!\n");
			printf("--------------------------------\n");
			computerscore++;
		}else if(winner == -1) {
			printf("--------------------------------\n");
			printf("Game Tie..\n");
			printf("--------------------------------\n");
		}else{
			printf("Unhandeled exception\n");
			return 1;
		}
		
		displayscore(userscore,computerscore);
		
		} // end game loop
	return 0;
}
