#include <cs50.h>
#include <stdio.h>

int main(void)

{
    //promt user for value of x
    int x = get_int("x: ");
    //promt user for value of y
    int y = get_int("y: ");
    //educational purposes, creation of z as an alterantive to printing x+y without saving the value
    int z = x+y;
    //print option 1: printing z which saves the result of x+y
    printf("%i\n",z);
    //print option 2: printing just x+y without saving the value
    printf("%i\n",x+y);
}