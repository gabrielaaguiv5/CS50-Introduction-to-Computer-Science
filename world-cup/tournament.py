# Simulate a sports tournament

import csv
import sys
import random

# Number of simluations to run
N = 1000


def main():

    # Ensure correct usage, input is compile to run the program and name of csv file
    if len(sys.argv) != 2:
        sys.exit("Usage: python tournament.py FILENAME")

    teams = []
    filename = sys.argv[1]  # Get name of file to open it with open function
    with open(filename) as file:  # Open file, dont use "r" because of conversion to int og rating
        reader = csv.DictReader(file)
        for row in reader:
            row["rating"] = int(row["rating"])  # Convert strings of rating into ints
            teams.append(row) #  Insert row set into teams[]


    counts = {}
    for i in range(N):
        winner = simulate_tournament(teams)  # Get winner of round N
        if winner in counts:
            counts[winner] += 1  # For teams who have already won
        else:
            counts[winner] = 1  # For first time winners


    # Print each team's chances of winning, according to simulation
    for team in sorted(counts, key=lambda team: counts[team], reverse=True):
        print(f"{team}: {counts[team] * 100 / N:.1f}% chance of winning")


def simulate_game(team1, team2):
    """Simulate a game. Return True if team1 wins, False otherwise."""
    rating1 = team1["rating"]
    rating2 = team2["rating"]
    probability = 1 / (1 + 10 ** ((rating2 - rating1) / 600))
    return random.random() < probability


def simulate_round(teams):
    """Simulate a round. Return a list of winning teams."""
    winners = []

    # Simulate games for all pairs of teams
    for i in range(0, len(teams), 2):
        if simulate_game(teams[i], teams[i + 1]):
            winners.append(teams[i])
        else:
            winners.append(teams[i + 1])

    return winners


def simulate_tournament(teams):
    """Simulate a tournament. Return name of winning team."""
    while len(teams) > 1:
        teams = simulate_round(teams)  # Dont stop simulation until only one winner
    return teams[0]["team"]  # Name to keep count of wins


if __name__ == "__main__":
    main()
