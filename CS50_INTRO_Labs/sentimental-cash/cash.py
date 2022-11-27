# Cash in Python
from cs50 import get_float
from math import floor


def main():

    cents = get_cents()  # Get change owed in dollars and check if its bigger than zero
    quarters = floor(cents/25)  # Get round lower quarters
    dimes = floor((cents - (quarters*25))/10)  # Get round lower dimes
    nickels = floor((cents - (quarters*25) - (dimes*10))/5)  # Get round lower nickels
    pennies = floor((cents - (quarters*25) - (dimes*10) - (nickels*5))/1)  # Because of size of 0.01 not rounding

    coins = quarters + dimes + nickels + pennies
    print(round(coins))  # Print rounded coins


def get_cents():
    while True:
        cents = get_float("Change owed: ")
        if cents > 0:
            return cents*100  # Return cents if value is bigger than zero and convert to dollars


main()

