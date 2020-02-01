/* We will implement the hardcore approach. The program will read
 * one character at a time and then reallocate the memory buffer
 * so that it becomes bigger. That way, we don't use a fixed size NTBS.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *getName() {
	char *input = malloc(sizeof(char));
	char ch = EOF;	
	unsigned int index = 1;

	while (ch) {
		ch = getc(stdin);	// Get a character from standard input

		if (ch == EOF || ch == '\n')
			ch = 0;
		input[index - 1] = ch;
		index++;

		input = realloc(input, index);
	}

	return input;
}

int main(int argc, char const *argv[])
{
	char *first_name, *last_name;

	printf("Enter your first name, please >>> \n");
	first_name = getName();

	printf("Enter your last name, please >>> \n");
	last_name = getName();

	printf("Hello, %s %s\n", first_name, last_name);
	return 0;
}