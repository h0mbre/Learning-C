## Assignment 22
More structs? God no, please no. I'm sorry, but yes. One more struct excercise. We're putting arrays in our structs, we're leveling up. 

The goal here is to create a program that takes input for five player's point totals and games played totals and then calculates the scoring averages for each player. Create a struct with members for total points and games played. Create an array of structures that is five elements deep (one for each player) and loop through the array filling it with the point totals and games played totals for each player. 

This array of structs should look like this in pseudo code:
```c
struct stats {
  int points;
  int games;
};

struct stats player[5];
```

You can declare an `int` counter variable and use it to iterate through the array for both points and games. 

## Example Output
```terminal_session
tokyo:~/LearningC/ # ./assignment22                                          
Enter Player 1's point total: 44
Enter Player 1's game total: 5
Enter Player 2's point total: 21
Enter Player 2's game total: 5
Enter Player 3's point total: 33
Enter Player 3's game total: 5
Enter Player 4's point total: 67
Enter Player 4's game total: 5
Enter Player 5's point total: 8
Enter Player 5's game total: 5
Player 1's scoring average was 8.80 ppg.
Player 2's scoring average was 4.20 ppg.
Player 3's scoring average was 6.60 ppg.
Player 4's scoring average was 13.40 ppg.
Player 5's scoring average was 1.60 ppg.
```

