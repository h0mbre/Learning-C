#include <stdio.h>

#define PIE 3.14

int main(int argc, char const *argv[])
{
	float radius, area;

	printf("Please enter the radius of the circle >>> \n");
	scanf("%f", &radius);
	area = PIE * radius * radius;	// PIE * r^2

	printf("The area of the circle with radius [%f] is [%f]\n", 
		radius, area);
	return 0;
}