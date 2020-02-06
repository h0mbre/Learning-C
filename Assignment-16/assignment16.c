#include <stdio.h>

int main(void)
{
	int array[10];

	printf("%p", array);
	printf("%p\n", &array[0]);
}
