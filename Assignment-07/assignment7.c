#include <stdio.h>


int main(void)
{
  //initialize vars and get their values
  float a,b,c,x;
  printf("Enter the value of variable \'A\': ");
  scanf("%f", &a);
  printf("Enter the value of variable \'B\': ");
  scanf("%f", &b);
  printf("Enter the value of variable \'C\': ");
  scanf("%f", &c);

  //start doing the math
  float solution1, solution2;
  solution1 = (-b + sqrt((b*b)-(4*a*c)))/(2*a);
  solution2 = (-b - sqrt((b*b)-(4*a*c)))/(2*a);

  //plug the solution back into the equation and check that it's correct: 0 = ax^2 + bx + c
  if (((a*(solution1*solution1)) + (b*solution1) + c) == 0) 
  {
  	printf("The solution using the '+' operator is: %f\n", solution1);
  }
  else
  {
  	printf("The solution using the '+' operator is: %f, but you might want to double-check that...\n", solution1);
  }
  
  if (((a*(solution2*solution2)) + (b*solution2) + c) == 0) 
  {
  	printf("[The solution using the '-' operator is: %f", solution2);
  }
  else
  {
  	printf("The solution using the '-' operator is: %f, but you might want to double check that...\n", solution2);
  }

  return 0;
}
