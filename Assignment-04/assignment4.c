#include <stdio.h>
#include <stdlib.h>

//define a value for PIE
#define PIE 3.14

int main(void)
{
  //initialize variable
  float radius;

  //get user input and store it
  printf("Enter the radius of your circle:\n ");
  scanf("%f ", &radius);

  //do the maths
  float area;
  area = PIE * (radius * radius);

  printf("\nThe area of your circle is %f", area);


}
