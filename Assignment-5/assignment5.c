#include <stdio.h>


int main(void)
{
  //initialize var
  float seconds;
  
  //get value for var
  printf("Enter the amount of seconds: ");
  scanf("%f", &seconds);

  //initialize our arithmetic vars
  float hours;
  float mins;
  float remaining_seconds;

  //make sure the hours value is a whole number that doesn't consider the decimal by using the (int) operation. 
  //for instance, 1.2 hours will be stored in hours as 1.0 here
  hours = (int)(seconds / 3600);
  
  //repeat for mins
  mins = (int)((seconds - (hours * 3600))/60);
  
  //remaining_seconds is simply what's leftover
  remaining_seconds = (seconds - (hours * 3600) - (mins * 60));
  printf("%0.0f seconds is equal to %0.0f hours, %0.0f minutes, and %0.0f seconds.", seconds, hours, mins, remaining_seconds);

  return 0;
}
