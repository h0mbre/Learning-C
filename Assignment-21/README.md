## Assignment 21
Design a struct which will have members that describe an employee's: last name, first name, date of birth, last 4 of SSN, and job title. Design a second struct which will store four employee names as members. The employee names will be structures of the type of your first struct. Inside of `main()`, prompt the user to enter each employee's credentials and store them. Finally, print every employee's credentials to the terminal.

Pseudo Code:
```c
first struct {
  members like: names, DOB, etc
  };
  
second struct {
  struct first_struct employee_name_1;
  } employees;
  
int main () {
  prompting and storing credentials for all employees;
  printing all the data to the terminal;
  };
```
