#include <stdio.h>
#include <stdlib.h>
#include "library.h"
#include <time.h>
#include <string.h>

int main() {
		
	int players_count;
	srand(time(NULL));	


	// enter the numbers of players which should be either 1 or 2 or 3 or 4
	
	do {
		printf("Enter the number of players: ");
		scanf("%d",&players_count);
	}while(players_count < 1 || players_count > 4);

	// initialize the structure;
	struct Players players[players_count];

	// ask the user details
	//
	int loop = 0;	
	if (loop) { // dev mode only
	for (int i=0;i<players_count;i++) {
		printf("\nEnter your name: ");
		scanf("%s",players[i].name);
		getchar();
		printf("\nEnter the color: ");
		scanf("%c",&players[i].color);
		getchar();
		players[i].pos = 0;
		players[i].id = i;
	}
	
	// display the structure 
	//
	for (int i=0;i<players_count;i++) {
		printf("Player Name: %s\n",players[i].name);
		printf("Color: %c\n",players[i].color);
		printf("Position: %d\n\n", players[i].pos);

	}
	}else{
		strcpy(players[0].name,"Ram");
		players[0].color = 'R';
		players[0].pos = 0;
		prayers[i].id = 0;

	} // dev mode loop end
	  //
	// game loop
	//
	int count = 0;
	int to_hold;
	int loop_count = 0;
	while(1) {
		// generate random number between 1 and 6	
		int player = loop_count % players_count;
		printf("%s : Enter key to roll the dice \n", players[player]);
		scanf("%d",&to_hold); // just to hold the screen
		printf("You got: %d\n",roll_dice());

		move_gotti(players[player],)
		
		moveGotti()
		if ( count == 6)
			break;
		count++;	
	}
	// game loop ends

	return 0;
}
