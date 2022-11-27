import cs50

try:
    x = cs50.get_int("X: ")

except:
    print("This is not an int!")
    exit()

try:
    y = cs50.get_int("Y: ")

except ValueError:
    print("This is not an int!")
    exit()

z = x + y

print(z)
