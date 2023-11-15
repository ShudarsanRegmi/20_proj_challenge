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
		printf("Enter the number of players (2 or 3 or 4): ");
		scanf("%d",&players_count);
		getchar();
	}while(players_count < 2 || players_count > 4);

	// initialize the structure;
	struct Players players[players_count];

	// ask the user details
	// for dev mode
	int loop = 1;	
	if (loop) { // dev mode only
	for (int i=0;i<players_count;i++) {
		printf("----------Enter the player details---------\n");
		printf("Enter your name: ");
		scanf("%s",players[i].name);
		getchar();

		do {
			printf("Enter the color:(R/B/Y/G) ");
			scanf("%c",&players[i].color);
			getchar();
		}while( !(players[i].color == 'R' || players[i].color == 'B' || players[i].color == 'Y' || players[i].color == 'G'));


		players[i].pos = 0;
		players[i].id = i;
		printf("-------------------------------------\n");
	}
	
	// display the structure 
	//
	for (int i=0;i<players_count;i++) {
		printf("Player Name: %s\n",players[i].name);
		printf("Color: %c\n",players[i].color);
		/* printf("Position: %d", players[i].pos); */

	}
	printf("\n-------------------------------------\n\n");


	}else{
		strcpy(players[0].name,"Ram");
		players[0].color = 'R';
		players[0].pos = 0;
		players[0].id = 0;

	} // dev mode loop end
	  //

	int count = 0;
	int to_hold;
	int loop_count = 0;
	// game loop
	while(1) {

		// implementation for three sixes to start.. will be done at last

		// generate random number between 1 and 6	
		int player = loop_count % players_count;

		int ako = 0;
		int total_ako = 0;
		do {
			printf("%s: Press Enter key to roll the dice:", players[player].name);
			getchar();
			ako = roll_dice();
			printf("You got  = %d\n",ako);
			total_ako = total_ako+ako;
			if(ako == 6 ) {
				printf("Got 6 !! Roll again\n");
			}
		
		}while(ako == 6);


		printf("Total got = %d\n",total_ako);

		int game_track = move_gotti(&players[player], total_ako);
		
		if(game_track != -1) {
			printf("-----------------------------------------------------\n");
			printf("Winner !! Winner !!: %s\n",players[player].name);
			printf("-----------------------------------------------------\n");
			break;
		}
		loop_count++;	
		/* printf("\033[H\033[J"); */
		show_score_card(players, players_count);
	}
	// game loop ends
	//

	return 0;
}
