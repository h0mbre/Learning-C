#include<stdio.h>
//author: Siddhanta Das
//date of creation: 25/02/20
int main(void)
{
int num,deno;
float remainder;
printf("enter the numerator \n");
scanf("%d",&num);
printf("enter the denominator \n");
scanf("%d",&deno);
if ((num%deno)==0)
{
    printf("there is no remainder \n");
}
else
{
    printf("there is remainder \n");
}
remainder=(num%deno);
printf("remainder is %f",remainder);

}
