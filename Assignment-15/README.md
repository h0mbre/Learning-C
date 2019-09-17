## Assignment 15
+ Create an `int` variable with `int variable`.
+ Create variable that is a pointer to the `int` variable with `int *ptr = &variable`.

Use the following variable references to replace the `x` in the appropriate print statements below:
+ `*ptr`
+ `variable`
+ `ptr`
+ `&variable`

Print statements:
+ `printf("The value of int variable is: %d\n", x);`
+ `printf("The value of the pointer to the int variable is: %d\n", x);`
+ `printf("The memory address of the int variable is: %d\n", x);`
+ `printf("The value held at the memory location that the pointer is pointing to is: %d\n", x);`

Hint: Google and read about pointers

Extra Credit: There's more than one set of correct answers! Find a different way to get the same output. 

## Example Output
```terminal_session
tokyo:~/LearningC/ # ./test                                        
The value of int variable is: 15
The value of the pointer to the int variable is: -1082059800
The memory address of the int variable is: -1082059800
The value held at the memory location that the pointer is pointing to is: 15
```
