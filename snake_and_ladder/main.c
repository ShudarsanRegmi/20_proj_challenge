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
		getchar();
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
		players[0].id = 0;

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

		int ako = 0;
		int total_ako = 0;
		do {
			printf("%s : Press Enter key to roll the dice:", players[player].name);
			getchar();
			ako = roll_dice();
			printf("ako = %d\n",ako);
			total_ako = total_ako+ako;
			if(ako == 6 ) {
				printf("Got 6 \n");
			}
		
		}while(ako == 6);


		printf("Total ako = %d\n",total_ako);

		move_gotti(&players[player], total_ako);
		
		/* if ( count == 6) */
		/* 	break; */
		/* count++; */	
	}
	// game loop ends

	return 0;
}
