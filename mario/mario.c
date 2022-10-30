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
    for (int i = 0; i < level; i++)
    {
        do {
            printf(" ");
            for (int j = level-(level-1); j < level; j++)
        {
            printf("#");
            printf("\n");

         }
         } while (i == level-i-1);



         break;

    }
    printf("\n");
}

//print number of spaces