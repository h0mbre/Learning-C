#include <stdio.h>

int main(void) {
  // initialize var
  int seconds;
  int remaining_seconds;
  int mins;
  int remaining_mins;
  int hours;
  int remaining_hours;
  int days;

  // get value for var
  printf("Enter the amount of seconds: ");
  scanf("%d", &seconds);

  // initialize our arithmetic vars
  remaining_seconds = seconds % 60; // 0 ~ 59
  mins = seconds / 60;
  remaining_mins = mins % 60;       // 0 ~ 59
  hours = mins / 60;
  remaining_hours = hours % 24;     // 0 ~ 23
  days = hours / 24;

  // Try more! Figure out months and years!
  // Note: <https://en.wikipedia.org/wiki/Leap_year>
  //
  // If days and hours are both equal to 0,
  // and I only want to display minutes and seconds, what should I do?

  printf(
      "%d seconds is equal to %d days, %d hours, %d minutes, and %d seconds.",
      seconds, days, remaining_hours, remaining_mins, remaining_seconds);

  return 0;
}
