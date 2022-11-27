# Cash in Python

def main():

    cents = get_cents()

def get_cents():
    while True:
        cents = int(input("Change owed: "))
        if cents > 0:
            return cents

main()
