#include <cs50.h>
#include <stdio.h>

int main(void)

{
    //promt user for value of x
    long x = get_long("x: ");
    //promt user for value of y
    long y = get_long("y: ");
    //educational purposes, creation of z as an alterantive to printing x+y without saving the value
    long z = x+y;
    //print option 1: printing z which saves the result of x+y
    printf("%li\n",z);
    //print option 2: printing just x+y without saving the value
    printf("%li\n",x+y);
}