## Assignment 18
Compile and run the following code and examine the output:

```c
#include <stdio.h>

void hello(void)
{
	char array[] = {72, 101, 108, 108, 111, 44, 32, 87, 111, 114, 108, 100, 33};

	printf("%s", array);
}

int main(void) 
{
	hello();
}
```

Now, compile this code and examine the output:

```c
#include <stdio.h>


void hello(void)
{
	char array[] = {72, 101, 108, 108, 111, 44, 32, 87, 111, 114, 108, 100, 33, '\0'};

	printf("%s", array);
}

int main(void) 
{
	hello();
}
```

What is the difference? Figure out why we need to terminate our array with `'\0'`. How did we print letters with `char` values in our array being integers? [Here](https://www.ascii-code.com/) is a great resource for looking up ASCII codes. 

Extra Credit: Try printing the array in both cases with `puts()` instead of `printf()`, notice anything different? 
