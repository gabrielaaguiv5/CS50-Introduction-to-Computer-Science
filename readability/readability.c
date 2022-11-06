#include <cs50.h>
#include <stdio.h>

int number_letters(string text);
int number_words(string text);
int number_sentences(string text);

int main(void)
{
    //Prompt user for text to test
    string text = get_string("Text: ");

    //Count number of letters
    int letters = number_letters(text);
    //Count number of words
    int words = number_words(text);
    //Count number of sentences
    int sentences = number_sentences(text);

    //Apply Coleman-Liau formula
    int grade = (0.0588*letters/words*100)-(0.296*sentences)-15.8;

    //Print Grade X
    if (grade > 0 && grade < 16)
    {
        printf("Grade %i\n", grade);
    }
    else
    {
        printf("Grade 16+");
    }

}

int number_letters(string text)
{
    return 0;
}

int number_words(string text)
{
    return 0;
}

int number_sentences(string text)
{
    return 0;
}