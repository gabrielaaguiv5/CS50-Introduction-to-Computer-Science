#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

bool only_digits(string key);
char rotate(char c, int n);

int main(int argc, string argv[])
{
    string key = argv[1];

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


bool only_digits(string key)
{
        for (int i = 0; i < strlen(key); i++)
        {
            if (!isdigit(key[i]))
                return false;
        }
        return true;
}


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