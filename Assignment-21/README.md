## Assignment 21
Design a struct which will have members that describe an employee's: 
+ last name, 
+ first name, 
+ employee ID number,
+ last 4 digits of their SSN, and
+ title.

Design a second struct which will store two employee names as members. The employee names will be structures of the type of your first struct. Inside of `main()`, prompt the user to enter each employee's credentials and store them. Finally, print the employee's credentials to the terminal.

Pseudo Code:
```c
first struct {
  members like: names, employee id, etc
  };
  
second struct {
  struct first_struct employee_1;
  } employees;
  
int main () {
  prompting and storing credentials for all employees;
  printing all the data to the terminal;
  };
```

## Example Output

