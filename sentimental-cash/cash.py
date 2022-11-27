# Cash in Python

def main():

    while True:
        cents = int(input("Change owed: "))
        if cents > 0:
            break
    return cents

    coins = quarters + dimes + nickels + pennies
    print(coins)

def quarters():
    cents = cents
    quarters = cents/25
    return quarters

def dimes():
    cents = cents - (quarters * 25)
    dimes = cents/10
    return dimes

def nickels():
    cents = cents - (dimes * 10)
    nickels = cents/5
    return nickels

def pennies():
    cents = cents - (nickels * 5)
    pennies = cents/1
    return pennies

main()
