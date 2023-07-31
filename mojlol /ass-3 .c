#include <stdio.h>


int main(){
    char first[20];
    char last[30];
    
    printf("enter your first and last name: ");
    scanf("%s%s",&first,&last);
    printf("first name;  %s\nlast name: %s ",first,last); 
    return 0;
}