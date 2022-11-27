# Cash in Python

def main():

    cents = get_cents()
    quarters = cents/25
    dimes = (cents - quarters)/10
    nickels = (cents - dimes)/5
    pennies = (cents - nickels)/1

    coins = quarters + dimes + nickels + pennies
    print(coins)


def get_cents():
    while True:
        cents = int(input("Change owed: "))
        if cents > 0:
            return cents

main()
