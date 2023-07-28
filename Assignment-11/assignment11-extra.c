#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main() {
  int score;
  char answer[] = "y";
  int count = 0;
  double average;

  do {
    printf("Enter a test score: ");
    scanf("%d", &score);
    average = (average * count + score) / (++count);
    printf("Would you like to continue? Y/N ");
    scanf("%s", answer);
  } while (strcmp(answer, "y") == 0 || strcmp(answer, "Y") == 0);

  printf("%.2f is the average.\n", average);
  return 0;
}
