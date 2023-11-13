#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int checkWinner(int user, int computer) {

	// 0 --> rock
	// 1 --> paper
	// 2 --> Scissor
	
	if(user == computer) {
		printf("tie\n");
		return -1; //  -1 signifies tie
	}
    // for RS -> R is the winner
	if ((user == 0 && computer == 2) || (user == 2 && computer == 0) ) {
		// rock is winner

		if(user == 0) {
			printf("user is winner");
			return 0;
			// user is winner
		}else{
			// computer is winner
			printf("computer is winner");
			return 1;

		}

		// RP --> paper winner
	}else if ((user == 0 && computer == 1) || (user == 1 && computer == 0)){
        // paper is winner
        if(user == 1) {
		    printf("user is winner");
		    return 0;
			// user is winner
		}else{
			// computer is winner
            printf("computer is winner");
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
            printf("computer is winner");
	    return 1;

		}
	    
	    
	}else{
	    printf("Unhandeled Exception");
	    return -1;
	}


}
int main() {
	// rock = 0
	int userscore = 0;
	int computerscore;
	int userchoice;
	int winner;
	int computerchoice;
	srand(time(NULL));
	while(1) {
	// main game loop
		// computer generate
		computerchoice = rand()%3;
		
		// asking user
		do {
			printf("\nPress 1 for Rock \nPress 2 for Paper \nPress 3 for Scissor\n");
			scanf("%d",&userchoice);
			
		} while (!(userchoice == 1 || userchoice == 2 || userchoice == 3));


		printf("You: %d\n",userchoice);
		printf("Computer: %d\n",computerchoice);	
	
		winner = checkWinner(userchoice-1, computerchoice);
	//int winner = 0;

		if(winner == 0) {
			printf("Your Score: %d\n",++userscore);
		}else if(winner == 1) {
			printf("Computer Score: %d\n",++computerscore);
		}else if(winner == -1) {
			printf("Game tie\n");
		}else{
			printf("Unhandeled exception\n");
			return 1;
		}
		
		} // end game loop
	return 0;
}
