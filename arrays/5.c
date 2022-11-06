#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int n = get_int("How many scores? ");
    int scores[n];
    float na;

    for (int i = 0; i < n; i++)
    {
        scores[i] = get_int("Score: ");
        do{
            na = 0 + n;
        }while (i < n);
    }
    printf("Average: %f\n", na / n);
}