#include <stdio.h>

int main(void)
{
	int array[10];

	printf("%p\n", array);
	printf("%p\n", &array[0]);

	return 0;
}
