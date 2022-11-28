# Mario in Python

def main():
    level = get_height()
    for row in range(1, level, 1):
        for spaces in range(1, row, 1):
            print("1", end="")
            for stars in range(0, row - 1, 1):
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
