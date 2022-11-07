#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    bool only_digits(string argv[]);
    {
        for (int i = 0, n = strlen(argv[1]); i < n; i++)
        {
            if (isdigit(argv[1][i]))
            {
                return true;
            }
        }
        return false;
    }
    //Promt user for an integer to be called k
    //If not given a single integer for k printf Usage: ./caesar key return 1 as value of main
    if (argc != 2 || argc > 2 )
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }




    //The given key 'k'
    //There are 26 characters in the alphabet but if k is 27 that should signify B which is A+1

    //When k is the wanted k printf plaintext: with get_string

    //With given plaintext printf ciphertext: which is plaintext rotated by k positions and return 0 as main
return 0;
}

