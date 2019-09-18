## Assignment 21
Design a struct which will have members that describe an employee's: 
+ last name, 
+ first name, 
+ employee ID number,
+ last 4 digits of their SSN, and
+ title.

Design a second struct which will store two employees as members. The employees will be structures of the type of your first struct. Inside of `main()`, prompt the user to enter each employee's credentials and store them. Finally, print the employee's credentials to the terminal.

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
```terminal_session
tokyo:~/LearningC/ # ./assignment21                                       
Enter the employee's first name: Roy
Enter the employee's last name: Higgins
Enter the employee's ID number: 345
Enter the last four digits of the employee's SSN: 9832
Enter the employee's job title (do not include the word 'Engineer'): Senior

Enter the employee's first name: Amanda
Enter the employee's last name: Nunes
Enter the employee's ID number: 678
Enter the last four digits of the employee's SSN: 4521
Enter the employee's job title (do not include the word 'Engineer'): Junior

Employee information for Roy Higgins: 
ID: 345
SSN: 9832
Title: Senior Engineer

Employee information for Amanda Nunes: 
ID: 678
SSN: 4521
Title: Junior Engineer#      
```
