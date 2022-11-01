#include <cs50.h>
#include <stdio.h>

int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);

int main(void)
{   int cents;
    int coins;
    // Ask how many cents the customer is owed //I implement the question "Change owed: "
    do
    {
        cents = get_int("Change owed: ");
    }
    while (cents < 0);


    // Calculate the number of quarters to give the customer
    int quarters = calculate_quarters(cents);
    cents = cents - (quarters * 25);

    // Calculate the number of dimes to give the customer
    int dimes = calculate_dimes(cents);
    cents = cents - (dimes * 10);

    // Calculate the number of nickels to give the customer
    int nickels = calculate_nickels(cents);
    cents = cents - (nickels * 5);

    // Calculate the number of pennies to give the customer
    int pennies = calculate_pennies(cents);
    cents = cents - (pennies * 1);

    // Sum coins
    coins = quarters + dimes + nickels + pennies;

    // Print total number of coins to give the customer
    printf("%i\n", coins);
}


int calculate_quarters(int cents)
{
    // Quarters return
    return cents/25;
}

int calculate_dimes(int cents)
{
    // Dimes return
    return cents/10;
}

int calculate_nickels(int cents)
{
    // Nickels return
    return cents/5;
}

int calculate_pennies(int cents)
{
    // Pennies return
    return cents/1;
}
