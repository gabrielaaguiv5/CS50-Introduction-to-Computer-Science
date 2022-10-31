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
    for (int rows = 1; rows < level; spaces++){
     for (int stars = 1; stars < level){

        do {
            printf("*");
            } while (spaces == spaces - stars);
        printf("* ");
        stars++;
    }

    }
    printf("\n");


}

//print number of spaces
