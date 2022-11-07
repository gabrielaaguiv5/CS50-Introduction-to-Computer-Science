#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    //Prompt user for text to test
    string text = get_string("Text: ");

    //Count number of letters
    int letters = count_letters(text);
    printf ("%i letters\n", letters);
    //Count number of words
    int words = count_words(text);
    printf ("%i words\n", words);
    //Count number of sentences
    int sentences = count_sentences(text);
    printf ("%i sentences\n", sentences);

    //Apply Coleman-Liau formula
    int grade = (0.0588*letters/words*100)-(0.296*sentences)-15.8;

    //Print Grade X
    if (grade > 0 && grade < 16)
    {
        printf("Grade %i\n", grade);
    }
    else if (grade < 0)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade 16+\n");
    }

}

int count_letters(string text)
{
    int count = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isalnum(text[i]))
        {
            count = count + 1;
        }
    }
    return count;
}

int count_words(string text)
{
    int countw = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if ((text[i]) == ' ')
        {
            countw = countw + 1;
        }
    }
    return countw + 1;
}

int count_sentences(string text)
{
    int counts = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] ==  '?')
        {
            counts = counts + 1;
        }
    }
    return counts;
}