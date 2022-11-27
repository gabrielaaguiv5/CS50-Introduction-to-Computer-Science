# Mario in Python

def main():
    level = get_height()
    for i in range(level-1):
        print(" ", end="#")
        print()
        for j in range(level):
            print("#", end="")
        print()


def get_height():
    while True:
        try:
            n = int(input("Height: "))
            if n > 0:
                break
        except ValueError:
            print("That's not an integer!")
    return n

main()
