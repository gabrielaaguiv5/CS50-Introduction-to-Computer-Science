# Readability in Python
from math import floor

txt = input("Text: ")  # Getting input text
x = floor(float(len(txt.split())))  # Round lower len of words
y = floor((float(len(txt.replace(" ", "").replace("'", "").replace(".", "").replace(
    ",", "").replace("!", "").replace(";", "").replace("?", "")))))  # Round to lower len of letters
k = floor(float(((txt.count("."))+(txt.count("!"))+(txt.count("?")))))  # Round to lower len of sentences

grade = (0.0588*y/x*100)-(0.296*k/x*100)-15.800  # Get grade

if grade > 0:
    if grade < 16:
        print(f"Grade {round(grade)}")  # For Grade between 0 and 16
elif grade < 0:
    print("Before Grade 1")  # For Grade below 1
if grade > 16:
    print("Grade 16+")  # For Grade higher than 16

