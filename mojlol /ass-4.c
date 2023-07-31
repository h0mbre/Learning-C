#include <stdio.h>
#include <math.h>
#define PI 3.14
int main(){

    float radius; 
    printf("enter the radius: ");
    scnaf("%f",&radius);
    float area= PI*pow(radius,2);
    printf("%f",area);
    return 0; 
}