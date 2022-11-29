import csv
import sys


def main():

    if len(sys.argv) != 3:
        sys.exit("Usage: python dna.py data.csv sequence.txt")

    # Read database file into a variable
    data = []
    filename = sys.argv[1]
    with open(filename) as file:
        reader = csv.DictReader(file)
        for row in reader:
            data.append(row)
        print(data)

    # Read DNA sequence file into a variable
    dna = 0
    filename2 = sys.argv[2]
    with open(filename2) as file:
        dna = file.read()

    # Find longest match of each STR in DNA sequence
    for i in range(1, len(data.fieldnames)):
     = longest_match(dna, "AGATC")
    b = longest_match(dna, "TTTTTTCT")
    c = longest_match(dna, "AATG")
    e = longest_match(dna, "TCTAG")
    f = longest_match(dna, "GATA")
    g = longest_match(dna, "TATC")
    h = longest_match(dna, "GAAA")
    i = longest_match(dna, "TCTG")



    # Check database for matching profiles
    for person in data:
        if data[1, 2, 3, 4, 5, 6, 7, 8] == data[a, b, c, e, f, g, h, i]:
            return data[0]
            print(data[0])


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
