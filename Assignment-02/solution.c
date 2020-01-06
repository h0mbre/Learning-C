#include <stdio.h>

int main(int argc, char const *argv[])
{
	int integer_variable = 1337;
	float float_variable = 7.64313;
	char char_variable = 'Z';

	printf("%d is an integer!\n", integer_variable);
	printf("%f is a float!\n", float_variable);
	printf("%c is a character!\n", char_variable);
	return 0;
}