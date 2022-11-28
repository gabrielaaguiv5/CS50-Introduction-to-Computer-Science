# Mario in Python

def main():
    level = get_height() # Get height input with function get_height
    for row in range(1, level+1):
        for spaces in range(level-row):
            print(" ", end="") # Print in row i level-row spaces
        for stars in range(row):
            print("#", end="") # Print in rown i, i number of #
        print()

def get_height():
    while True:
        try:
            n = int(input("Height: "))
            if n > 0:
                if n <= 8:
                    break # Among the bigger than zero filter only to accept lower than 8
        except ValueError:
            print("That's not an integer!")
    return n

main()
