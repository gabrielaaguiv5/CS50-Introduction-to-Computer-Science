# Mario in Python

def main():
    level = get_height()
    for row in range(level):
        for spaces in range(level-row):
            print("1", end="")
        for stars in range(row):
            print("#", end="")
    print()

def get_height():
    while True:
        try:
            n = int(input("Height: "))
            if n > 0:
                if n <= 8:
                    break
        except ValueError:
            print("That's not an integer!")
    return n

main()
