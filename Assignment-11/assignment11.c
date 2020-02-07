#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INITIAL_CAPACITY 3

int main(void)
{
  char answer[] = "y";

  //allocate store for 3 scores
  double *scores = malloc(INITIAL_CAPACITY * sizeof(double));
  if(!scores)
  {
    fprintf(stderr, "Failed to allocate scores array.\n");
    return 1;
  }

  int capacity = INITIAL_CAPACITY;

  //initialize a variable to increase and iterate through our array to store scores
  int numScores;

  for(numScores = 0; strcmp(answer, "y") == 0; ++numScores)
  {
    //dynamically
    if(numScores == capacity)
    {
      capacity *= 2;
      scores = realloc(scores, capacity * sizeof(double));
      if(!scores)
      {
        fprintf(stderr, "Failed to reallocate scores array.\n");
        return 1;
      }
    }

    //store input in our array
    printf("Enter a test score: ");
    scanf("%lf", &scores[numScores]);

    //ask the user if they would like to continue
    printf("Would you like to continue? y/n ");
    scanf("%s", &answer);
  }

  double sum = 0;

  //start a loop that will start at 0, and then it'll iterate through our scores array until it reaches the end
  //each element in the array will be added to the sum so that we can find the average
  for(int loop = 0; loop < numScores; loop++)
  {
    sum += scores[loop];
  }

  printf("%.2f is the average.\n", sum / numScores);

  free(scores);

  return 0;
}
