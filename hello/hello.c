#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //Introductory program, by Gabriela Aguilar.

    //Lets get to know each other! After the question type your preferred name.
    string answer = get_string("Welcome, What is your name? ");

    //Welcome! You should recieve a personalized salute.
    printf("Hello!, %s\n", answer);
}

//cd name of directory, make name of file, code new file, ./