# Cash in Python

def main()
cents = get_cents()
quarters = calculate_quarters(cents)
dimes = calculate_dimes(cents)
nickels = calculate_nickels(cents)
pennies = calculate_pennies(cents)

coins = quartes + dimes + nickels + pennies

def get_cents():
    while True:
        cents = int(input("Change owed: "))
        if cents > 0:
            break
    return cents

def calculate_quarters(cents):
    return cents/25

def calculate_dimes(cents):
    return cents/10

def calculate_nickels(cents):
    return cents/5

def calculate_pennies(cents):
    return cents/1
