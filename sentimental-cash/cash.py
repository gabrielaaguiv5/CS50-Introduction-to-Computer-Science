# Cash in Python

def main()
cents = get_cents()
quarters = calculate_quarters()
dimes = calculate_dimes()
nickels = calculate_nickels()
pennies = calculate_pennies()

coins = quarters + dimes + nickels + pennies

def get_cents():
    while True:
        cents = int(input("Change owed: "))
        if cents > 0:
            break
    return cents

def calculate_quarters():
    return cents/25

def calculate_dimes():
    
    return cents/10

def calculate_nickels():
    return cents/5

def calculate_pennies():
    return cents/1
