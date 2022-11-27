from cs50 import get_int


def main():
   height = get_height()
   for i in range(height):
 9 print("#")
10
11
12 def get_height():
13 while True:
14 n = get_int("Height: ")
15 if n > 0:
16 return n
17
18
19 main()