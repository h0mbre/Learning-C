#include <stdio.h>

//define stats struct
struct stats {
	int points;
	int games;
};

//create instance of 5 players stats structs
struct stats players[5];

int counter;

int main (void)
{
	//loop through getting input for both stats members for each stats players struct
	for (counter = 0; counter < 5; counter++)
	{
		printf("Enter Player %d's point total: ", (counter + 1));
		scanf("%d", &players[counter].points);

		printf("Enter Player %d's game total: ", (counter + 1));
		scanf("%d", &players[counter].games);
	}

	printf("\n");
	
	//you know this by now, you're a C god
	for (counter = 0; counter < 5; counter++)
	{
		float average = (float)(players[counter].points)/(players[counter].games);

		printf("Player %d's scoring average was %.2f ppg.\n", (counter + 1), average);
	}
	
	return 0;
}
