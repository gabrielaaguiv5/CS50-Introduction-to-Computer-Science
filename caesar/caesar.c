#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

bool only_digits(string input);
char rotate(char c, int n);

int main(int argc, string argv[])
{
    string key = argv[1];
    //If not given a single integer for k printf Usage: ./caesar key return 1 as value of main

    if (argc != 2 || argc > 2 || !only_digits(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    int k = atoi(argv[1]);

    string plaintext = get_string("plaintext: ");

    printf("ciphertext: ");
    for (int i = 0, nm = strlen(plaintext); i < nm; i++)
    {
        char c = plaintext[i];
        rotate(c, k);
    }
printf("\n");
return 0;
}





bool only_digits(string input)
{
        for (int i = 0, n = strlen(input); i < n; i++)
        {
            if (!isdigit(input[1][i]))
            {
                printf("Usage: ./caesar key\n");
                return false;
            }
        }
        return true;
}


    //Promt user for an integer to be called k
    //Check if given k is digits

    //The given key 'k'
    //There are 26 characters in the alphabet but if k is 27 that should signify B which is A+1

    //When k is the wanted k printf plaintext: with get_string

    //With given plaintext printf ciphertext: which is plaintext rotated by k positions and return 0 as main


char rotate(char c, int n)
{
    if (isupper(c))
    {
        return printf("%c",(((c - 'A') + n) %26) + 'A');
    }
    else if (islower(c))
    {
        return printf("%c",(((c - 'a') + n) %26) + 'a');
    }
    else
    {
        return printf("%c",(c));
    }
}