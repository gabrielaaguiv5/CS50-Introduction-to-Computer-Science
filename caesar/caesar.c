#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

char rotate(char *, int n);

int main(int argc, string argv[])
{
    string key = argv[1];
    //If not given a single integer for k printf Usage: ./caesar key return 1 as value of main

    if (argc != 2 || argc > 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    //Promt user for an integer to be called k
    //Check if given k is digits
    bool only_digits(string argv[]);
    {
        for (int i = 0, n = strlen(argv[1]); i < n; i++)
        {
            if (isdigit(argv[1][i]))
            {
                return true;
            }
        }
        printf("Usage: ./caesar key\n");
        return false;
     }

    //The given key 'k'
    //There are 26 characters in the alphabet but if k is 27 that should signify B which is A+1
    int k = atoi(argv[1]);
    //When k is the wanted k printf plaintext: with get_string
    string plaintext = get_string("plaintext: ");
    //With given plaintext printf ciphertext: which is plaintext rotated by k positions and return 0 as main
    printf("ciphertext: ");
    rotate(*plaintext, k);






return 0;
}


char rotate(char *t, int n)
{
    for (int i = 0, nm = strlen(*plaintext); i < nm; i++)
    {

    }
}