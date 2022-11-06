#include <stdio.h>
#include <cs50.c>

int main(void)
{
    int scores[3];

    for (int i = 0; i < 3; i++)
    {
        scores[i] = get_int("Score: ");
    }
    
}