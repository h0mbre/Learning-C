## Assignment 23
Create a simple structure of your choice. Mine will have a single member, an `int` called `integer`. Do not create an instances of the struct yet. Declare a pointer variable that points to your struct. This pointer doesn't actually point to anything yet because there are no instances of the first struct. Create an instance of the struct. Now initialize your pointer to point to the struct instance.

Finally, assign values to the integer member of your original struct in three ways:
+ assign a value by using standard dot-notation for your instance and then print the value
+ assign a value by using standard dot-notation for the pointer initialized to the instance and then print the value
+ assign a value by using the -> indirect membership operator between the pointer name and the structure member and then print the value

## Pseudo Code
```c
struct example
{
  int integer;
};

struct example *ptr;

struct example test;

<pointer initialization statement>

test.integer = x;
print 

(*ptr).integer = y;
print

ptr->integer = z;
print
```

## Example Output
```terminal_session
tokyo:~/LearningC/ # ./assignment23                                        
5
6
7   
```
