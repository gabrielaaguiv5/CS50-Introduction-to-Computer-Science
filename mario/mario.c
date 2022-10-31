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
    for (int spaces = 0; spaces < level; spaces++)
    { for (int stars = 1)
    {
        do {
            printf(" ");
            } while (spaces - stars);

    }
    }

}

//print number of spaces
