import cs50
try:
    x = cs50.get_int("X: ")

except ValueError:
    print("This is not an int!")

try:
    y = cs50.get_int("Y: ")

except ValueError:
    print("This is not an int!")

z = x + y

print(z)

x1 = int(input("X: "))

y1 = int(input("Y: "))

za = x1 + y1

print(za)