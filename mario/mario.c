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

    int stars = 1;
    int spaces = 0;
    //print a number of spaces and hashes for each row
    for (spaces; i < level; spaces++;stars)
    {
        do {
            printf(" ");
            } while (i == level-i-1);

            for (int j = 0; j < level; j++)
        {
            printf("#");
            printf("\n");

         }




         break;

    }
    printf("\n");
}

//print number of spaces