#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //promt user for input for piramid
    //get_int cause it should only be numbers
    do{
        int level=get_int("Height: ");
    }
    while level>8 || level<0
    //print a number of spaces and hashes for each row

}