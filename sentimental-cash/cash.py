# Cash in Python

def main():

    cents = get_cents()
    quarters = cents//25
    dimes = (cents - (quarters*25))//10
    nickels = (cents - (dimes*10))//5
    pennies = (cents - (nickels*5))//1

    coins = quarters + dimes + nickels + pennies
    print(round(coins))


def get_cents():
    while True:
        cents = int(input("Change owed: "))
        if cents > 0:
            return cents

main()
