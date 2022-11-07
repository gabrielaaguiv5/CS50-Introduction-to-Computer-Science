#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

//Declaring functions
int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    //Prompt user for text to test
    string text = get_string("Text: ");

    //Count number of letters
    int letters = count_letters(text);

    //Count number of words
    int words = count_words(text);

    //Count number of sentences
    int sentences = count_sentences(text);


    //Apply Coleman-Liau formula
    float grade = (0.0588*letters/words*100)-(0.296*sentences/words*100)-15.8;


    //Print Grade if between 1 and 16, if less than 1, and if more than 16
    if (grade > 0 && grade < 16)
    {
        printf("Grade %i\n", (int) lroundf(grade));
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

//To count letters it is needed to check if alphanumeric and not to count spaces
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

//To count words it is needed to count spaces and add 1 for last word
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

//To count sentences it is needed to count punctuation
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