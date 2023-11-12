#include <stdio.h>
int checkWinner(char user, char computer) {


	if(user == computer) {
		printf("tie");
		return -1; //  -1 signifies tie
	}
    // for RS -> R is the winner
	if ((user == 'R' && computer == 'S') || (user =='S' && computer == 'R') ) {
		// rock is winner

		if(user == 'R') {
		    printf("user is winner");
			// user is winner
		}else{
			// computer is winner
        printf("computer is winner");

		}

		// RP --> paper winner
	}else if ((user == 'R' && computer == 'P') || (user == 'P' && computer == 'R')){
        // paper is winner
        if(user == 'P') {
		    printf("user is winner");
			// user is winner
		}else{
			// computer is winner
            printf("computer is winner");

		}
      // PS --> Scissor is winner  
	}else if ((user == 'P' && computer == 'S') || (user == 'S' && computer == 'P')){
        // scissor is winner
        if(user == 'S') {
		    printf("user is winner");
			// user is winner
		}else{
			// computer is winner
            printf("computer is winner");

		}
	    
	    
	}else{
	    printf("Unhandeled Exception");
	}


}

int main() {
	// rock = 0
	while(1) {
	// main game loop
		// computer generate
		
		// asking user
		
	} // end game loop
	
	
	return 0;
}
