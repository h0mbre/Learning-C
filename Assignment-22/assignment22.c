#include <stdio.h>

struct stats {
	int points;
	int games;
};

struct stats players[5];

int counter;

int main (void)
{
	for (counter = 0; counter < 5; counter++)
	{
		printf("Enter Player %d's point total: ", (counter + 1));
		scanf("%d", &players[counter].points);

		printf("Enter Player %d's game total: ", (counter + 1));
		scanf("%d", &players[counter].games);
	}

	printf("\n");
	
	for (counter = 0; counter < 5; counter++)
	{
		float average = (float)(players[counter].points)/(players[counter].games);

		printf("Player %d's scoring average was %.2f ppg.\n", (counter + 1), average);
	}
	
	return 0;
}
