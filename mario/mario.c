#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int level;
    //promt user for input for piramid
    //get_int cause it should only be numbers
    do{
        level = get_int("Height: ");
    }
    while (level > 8 || level < 0);

    //print a number of spaces and hashes for each row
    for (int rows = 1; rows <= level; rows++){
        for (int stars = 0; stars <= level-rows; stars++){
            printf("*");
            }

            printf("*");
            printf("\n");

    }
}

