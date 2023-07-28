#include <stdio.h>


int main(int argc, char *argv[])
{
  
  if(argc != 3) 
  {
  	printf("Usage: ./assignment9 Firstname Lastname");
  }
  else
  {
    // 0: the name of the program
    // 1: Firstname
    // 2: Lastname
  	printf("Hello, %s %s", argv[1], argv[2]);
  }
  return 0;
}
