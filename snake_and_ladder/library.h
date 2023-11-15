#ifndef LIBRARY_H
#include <stdio.h>
#include <stdlib.h>
#define LIBRARY_H
#endif

#define NO_OF_SNAKES 10
#define NO_OF_LADDERS 9

struct Players {
	int id;
	char name[20];
	char color;
	int pos;
};

typedef struct Snakes {
	int from;
	int to;
} Snake;

typedef struct Ladders {
	int from;
	int to;
} Ladder;


/* snake snakes[no_of_snakes] = { {16, 6}, {47, 26}, {49, 11}, {56, 53}, {62, 19}, {64, 60}, {87, 24}, {93, 73}, {95, 75}, {98, 78} }; */
/* ladder ladders[no_of_ladders] = { {1, 38}, {4, 14}, {9, 31}, {21, 42}, {28, 84}, {36, 44}, {51, 67}, {71, 91}, {80, 99} }; */

Snake snakes[NO_OF_SNAKES] = { {6, 1}, {5, 4}, {3,2}, {4,3}, {2, 1}, {64, 60}, {87, 24}, {93, 73}, {95, 75}, {98, 78} };
Ladder ladders[NO_OF_LADDERS] = { {1, 38}, {4, 14}, {9, 31}, {21, 42}, {28, 84}, {36, 44}, {51, 67}, {71, 91}, {80, 99} };

// functions
//
//
// the seed for random function

int roll_dice() {
	return (rand() % 6)+1;	
}

int check_snake(int pos) {
	for(int i=0; i<NO_OF_SNAKES; i++) {
		if (pos == snakes[i].from) {
			return 1;	
		}
	}
	return 0;
}

int check_ladder(int pos) {
	for(int i=0; i<NO_OF_LADDERS; i++) {
		if (pos == ladders[i].from) {
			return 1;	
		}
	}
	return 0;
}

int get_chere_pachi_ko_pos(int mukh_ko_number) {
	for(int i=0;i<NO_OF_SNAKES;i++) {
		if(mukh_ko_number == snakes[i].from) {
			printf("Sarpa veteo..\n");
			printf("Chhering to: %d\n",snakes[i].to);
			return snakes[i].to;
		}

	}

}

int get_chade_pachi_ko_pos(int tala_ko_number) {
	for(int i=0;i<NO_OF_LADDERS;i++) {
		if(tala_ko_number == ladders[i].from) {
			printf("Sidhi veteo..\n");
			printf("Chhadding to: %d\n",ladders[i].to);
			return ladders[i].to;
		}

	}
}
int move_gotti(struct Players p,  int step) {
	printf("Turn: %s\n",p.name);
	printf("Current Position: %d\n",p.pos);
	printf("Step: %d\n",step);

	int temp_pos = p.pos+step;	
	int final_pos = temp_pos;	
	// if temp_pos has got snake: i.e.  is temp_pos number there in snakes array
	if(check_snake(temp_pos)) {
		printf("You got the snake");
		final_pos = get_chere_pachi_ko_pos(temp_pos);	
		printf("Final Pos: %d\n",final_pos);
		
	}


	// if temp_pos has got ladder: i.e. is temp_pos number there in ladder array
	
	if(check_ladder(temp_pos)) {
		printf("You got the ladder");
		final_pos = get_chade_pachi_ko_pos(temp_pos);
		printf("Final Pos: %d\n",final_pos);
		
	}

	// change position
	p.pos = final_pos;
	printf("your new position: %d\n",p.pos);

	
	
	//
}

