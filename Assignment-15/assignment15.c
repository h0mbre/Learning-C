#include <stdio.h>

int main(void)
{
  //declare int variable and a pointer to the int variable
  int variable = 15;
  int *ptr = &variable;

  //standard, just printing the value
  printf("The value of int variable is: %d\n", variable);

  //since we assigned the pointer to 'variable', our pointer's value is now the memory address of 'variable'
  printf("The value of the pointer to the int variable is: %p\n", ptr);

  //using the ampersand before variable means we're printing it's memory address instead of it's value
  printf("The memory address of the int variable is: %p\n", &variable);

  //using the asterisk means we will print the value held at the memory address pointed to by the pointer
  printf("The value held at the memory location that the pointer is pointing to is: %d\n", *ptr);

  return 0;
}
