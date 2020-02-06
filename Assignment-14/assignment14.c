#include <stdio.h>

int main(void)
{
	int number = 21;

	int *ptr = &number;

	printf("The value of our pointer is: %p", ptr);

	return 0;
}
