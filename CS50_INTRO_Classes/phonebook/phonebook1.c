#include <stdio.h>
#include <cs50.h>
#include <string.h>

typedef struct
{
    string name;
    string number;
}
person;

int main(void)
{
    person user[2];

    user[0].name = "Carter";
    user[0].number = "+1-617-495-1000";

    user[1].name = "David";
    user[1].number = "+1-949-468-2750";

    for (int i = 0; i < 2; i++)
    {
        if (strcmp(user[i].name, "David") == 0)
        {
            printf("Found %s\n", user[i].number);
            return 0;
        }
    }
    printf("Not found\n");
    return 1;
}