# Mario in Python

def main():
    c = 1
    rows = 1
    level = get_height()
    for i in range(1, rows, 1):
        for k in range(1, level-c, 1):
            print(" ", end="")
            print()
            for j in range(0, rows - 1, 1):
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
