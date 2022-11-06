#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int n = get_int("How many scores? ");
    int scores[n];
    int i = 0;
    float na;

    for (i < n; i++)
    {
        scores[i] = get_int("Score: ");

    }

    na = 0 + scores[i];

    printf("Average: %f\n", na / n);
}