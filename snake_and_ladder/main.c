#include <stdio.h>
#include "library.h"

int main() {
		
	int players_count;
	


	// enter the numbers of players which should be either 1 or 2 or 3 or 4
	
	do {
		printf("Enter the number of players: ");
		scanf("%d",&players_count);
	}while(players_count < 1 || players_count > 4);

	// initialize the structure;
	struct Players players[players_count];

	// ask the user details
	for (int i=0;i<players_count;i++) {
		printf("\nEnter your name: ");
		scanf("%s",players[i].name);
		getchar();
		printf("\nEnter the color: ");
		scanf("%c",&players[i].color);
		getchar();
		players[i].pos = 0;
	}
	
	// display the structure 
	//
	for (int i=0;i<players_count;i++) {
		printf("Player Name: %s\n",players[i].name);
		printf("Color: %c\n",players[i].color);
		printf("Position: %d\n\n", players[i].pos);

	}


	return 0;
}
