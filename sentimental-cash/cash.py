# Cash in Python

def main()
cents = get_cents()
quarters = calculate_quarters(cents)
dimes = calculate_dimes(cents)
pennies = calculate_pennies(cents)

coins = quartes + dimes + nickles + pennies

def get_cents():
    while True:
        cents = int(input("Change owed: "))
