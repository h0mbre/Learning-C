#include <stdio.h>
#include <stdlib.h>

//define structure
struct struct_name
{
	int integer;
	char character;
	float floatie;
//give an instance of the structure the name 'example'
} example;

int main (void)
{
	//use the . notation to refer to the members of the 'example' instance of the 'struct_name' struct
	example.integer = 50;
	example.character = 'W';
	example.floatie = 3.14;

	printf("This is the int: %d", example.integer);
	printf(", this is the char: %c", example.character);
	printf(", this is the float: %.2f\n", example.floatie);
	
	return 0;
	
}
