#include <stdio.h>

int main(int argc, char const *argv[])
{
	/* Numerator = top number of a fraction
	 * Denominator = Bottom number of a fraction
	 */
	unsigned int numerator, denominator;

	printf("Enter the numerator >>> ");
	scanf("%d", &numerator);
	printf("Enter the denominator >>> ");
	scanf("%d", &denominator);

	if (numerator % denominator) {
		printf("There is a remainder.\n");
	}
	else{
		printf("There is NOT a remainder.\n");
	}
	
	return 0;
}