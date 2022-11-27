# Cash in Python

def main():
    quarters = calculate_quarters()
    dimes = calculate_dimes()
    nickels = calculate_nickels()
    pennies = calculate_pennies()

    coins = quarters + dimes + nickels + pennies
    print(coins)

def get_cents():
    while True:
        cents = int(input("Change owed: "))
        if cents > 0:
            break
        return cents

def calculate_quarters():
    return cents/25

def calculate_dimes():
    cents = cents - (quarters * 25)
    return cents/10

def calculate_nickels():
    cents = cents - (dimes * 10)
    return cents/5

def calculate_pennies():
    cents = cents - (nickels * 5)
    return cents/1

main()
