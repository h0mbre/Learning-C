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

Hint: Notice in my output to the terminal the titles have a structure like `Lead Engineer` with a space in between. Make your print statements with <space> Engineer hardcoded, only input one word for the title. In this example, you'd only input 'Lead' as the employee's title. Otherwise, you may run into trouble with the `printf()` function's space reading abilities and formatting with `fgets()`. Example print statement for the title info: `printf("%s Engineer\n\n", engineering_dept.James.title);`
  
## Example Output
```terminal_session
tokyo:~/LearningC/ # ./assignment21                                          
Enter James' last name: Smith
Enter James' first name: James
Enter James' DOB in mm-dd-yy format: 06-21-87
Enter the last 4 digits of James' SSN: 1234
Enter James' title: Junior

Enter Amber's last name: Johnson
Enter Amber's first name: Amber
Enter Amber's DOB in mm-dd-yy format: 05-21-90
Enter the last 4 digits of Amber's SSN: 4567
Enter Amber's title: Junior

Enter Roger's last name: Rodgers
Enter Roger's first name: Roger
Enter Roger's DOB in mm-dd-yy format: 09-21-83
Enter the last 4 digits of Roger's SSN: 7821
Enter Roger's title: Lead

Enter Sarah's last name: James
Enter Sarah's first name: Sarah
Enter Sarah's DOB in mm-dd-yy format: 01-01-92
Enter the last 4 digits of Sarah's SSN: 5621
Enter Sarah's title: Senior

James info:
Smith
James
06-21-87
1234
Junior Engineer

Amber info:
Johnson
Amber
05-21-90
4567
Junior Engineer

Roger info:
Rodgers
Roger
09-21-83
7821
Lead Engineer

Sarah info:
James
Sarah
01-01-92
5621
Senior Engineer
```
