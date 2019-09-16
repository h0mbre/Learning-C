#include <stdio.h>


int main(void)
{
  
  int input;
  //ask user for number between 1 - 500

  printf("Enter a number between 1 and 500: ");
  scanf("%d", &input);

  if (input >= 0 && input <= 100)
  {
  	printf("Your number is between 1 and 100!");
  }

  else if (input >= 101 && input <= 200)
  {
  	printf("Your number is between 101 and 200!");
  }

   else if (input >= 201 && input <= 300)
  {
  	printf("Your number is between 201 and 300!");
  }

   else if (input >= 301 && input <= 400)
  {
  	printf("Your number is between 301 and 400!");
  }

   else if (input >= 401 && input <= 500)
  {
  	printf("Your number is between 401 and 500!");
  }

  else
  {
  	printf("Your number was not in any of our ranges.");
  }
  return 0;
}
