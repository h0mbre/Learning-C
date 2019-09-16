#include <stdio.h>
#include <string.h>


int main(void)
{
  char answer[] = "Y";

  float scores[10];
  
  //initialize a variable to increase and iterate through our array to store scores
  int i = 0;

  while (strcmp(answer, "Y") == 0)
  {
  
  	//store input in our array
  	printf("Enter a test score: ");
  	scanf("%f", &scores[i]);

  	//increase our counter
  	i++;

  	//ask the user if they would like to continue
  	printf("Would you like to continue? Y/N ");
  	scanf("%s", &answer);
  }

  int loop;
  int sum = 0;
  
  //start a loop that will start at 0, and then it'll iterate through our scores array until it reaches the end
  //each element in the array will be added to the sum so that we can find the average
  for(loop = 0; loop < i; loop++)
  {
  	sum = sum + scores[loop];
  }

  //do the maths
  float average;

  average = (float)sum/loop;

  printf("%.2f is the average.\n", average);
}
