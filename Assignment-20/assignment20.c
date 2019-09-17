#include <stdio.h>
#include <stdlib.h>

struct struct_name
{
	int integer;
	char character;
	float floatie;
} example;

int main (void)
{
	example.integer = 50;
	example.character = 'W';
	example.floatie = 3.14;

	printf("This is the int: %d", example.integer);
	printf(", this is the char: %c", example.character);
	printf(", this is the float: %.2f\n", example.floatie);
	
	return 0;
	
}
