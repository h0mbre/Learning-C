#include <stdio.h>
#include <string.h>

struct data {
char first[20];
char last[20];
int employee_id;
int last_4_SSN;
char title[20];
};

struct employees {
	struct data employee1;
	struct data employee2;
} engineering_dept;

int main(void)
{	
	
	//scanf the input into the correct variable
	//engineering_dept = name of the instance of the 'employees' struct
	//employee1 = member of the 'employees' struct
	//first = member of the 'data' struct
	//notice that employee1 and employee2 are 'data' struct instances themselves
	printf("Enter the employee's first name: ");
	scanf("%s", &engineering_dept.employee1.first);

	printf("Enter the employee's last name: ");
	scanf("%s", &engineering_dept.employee1.last);

	printf("Enter the employee's ID number: ");
	scanf("%d", &engineering_dept.employee1.employee_id);

	printf("Enter the last four digits of the employee's SSN: ");
	scanf("%d", &engineering_dept.employee1.last_4_SSN);

	printf("Enter the employee's job title (do not include the word \'Engineer\'): ");
	scanf("%s", &engineering_dept.employee1.title);

	printf("\nEnter the employee's first name: ");
	scanf("%s", &engineering_dept.employee2.first);

	printf("Enter the employee's last name: ");
	scanf("%s", &engineering_dept.employee2.last);

	printf("Enter the employee's ID number: ");
	scanf("%d", &engineering_dept.employee2.employee_id);

	printf("Enter the last four digits of the employee's SSN: ");
	scanf("%d", &engineering_dept.employee2.last_4_SSN);

	printf("Enter the employee's job title (do not include the word \'Engineer\'): ");
	scanf("%s", &engineering_dept.employee2.title);

	//print all the info we just stored for each employee
	printf("\nEmployee information for %s %s: ", engineering_dept.employee1.first, engineering_dept.employee1.last);
	printf("\nID: %d", engineering_dept.employee1.employee_id);
	printf("\nSSN: %d", engineering_dept.employee1.last_4_SSN);
	printf("\nTitle: %s Engineer", engineering_dept.employee1.title);

	printf("\n\nEmployee information for %s %s: ", engineering_dept.employee2.first, engineering_dept.employee2.last);
	printf("\nID: %d", engineering_dept.employee2.employee_id);
	printf("\nSSN: %d", engineering_dept.employee2.last_4_SSN);
	printf("\nTitle: %s Engineer", engineering_dept.employee2.title);


	return 0;
}
