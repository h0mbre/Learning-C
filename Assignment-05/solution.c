#include <stdio.h>

int main(int argc, char const *argv[])
{
	unsigned int initialSeconds, hours, minutes, seconds;

	printf("Enter the amount of seconds >>> ");
	scanf("%d", &initialSeconds);
	seconds = initialSeconds;

	// Doing the math
	hours = seconds / 3600;
	seconds %= 3600;
	minutes = seconds / 60;
	seconds %= 60;

	// Printing the results
	printf("%d seconds equals to %d hours, %d minutes, %d seconds\n", initialSeconds,
	hours, minutes, seconds);
	return 0;
}