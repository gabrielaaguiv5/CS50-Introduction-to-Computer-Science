try:
    x1 = int(input("X: "))
except ValueError:
    print("This is not an int!")
    exit()
try:
    y1 = int(input("Y: "))
except ValueError:
    print("This is not an int!")
    exit()

za = x1 + y1

print(za)