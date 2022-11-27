# Cash in Python

def main():

    cents = get_cents()
    quarters = cents/25
    print(round(quarters))
    cents = cents - quarters
    print(round(cents))

def get_cents():
    while True:
        cents = int(input("Change owed: "))
        if cents > 0:
            return cents

main()
