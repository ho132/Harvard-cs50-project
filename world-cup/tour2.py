# Simulate a sports tournament

import csv
import sys
import random

# Number of simluations to run
N = 1000


def main():
        # Ensure correct usage
        if len(sys.argv) != 2:
            sys.exit("Usage: python tournament.py FILENAME")
        with open(sys.argv[1], "r") as file:
            c = csv.DictReader(file)
            teams = []  # Initialize an empty list to store team ratings
            for row in c:
                trate = int(row["rating"])  # Convert the team's rating to an integer
                teams.append(trate)  # Append the team's rating to the list 'teams'

        print(teams)

    counts = {}
    # TODO: Simulate N tournaments and keep track of win count
    for i in range(N):
        winner=simulate_tournament(teams)
        if winner in counts:
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
    # TODO
    while len(teams) > 1:
        teams = simulate_round(teams)
    return teams[0]["name"]


if __name__ == "__main__":
    main()
