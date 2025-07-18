import csv
import sys
import random

# Number of simulations to run
N = 1000

def main():
    # Ensure correct usage
    if len(sys.argv) != 2:
        sys.exit("Usage: python tournament.py FILENAME")
    with open(sys.argv[1], "r") as file:
        c = csv.DictReader(file)
        teams = []  # Initialize an empty list to store team ratings
        for row in c:
            team_data = {"team": row["team"], "rating": int(row["rating"])}
            teams.append(team_data)

    # TODO: Read teams into memory from file

    counts = {}
    # Simulate N tournaments and keep track of win counts
    for _ in range(N):
        x = simulate_tournament(teams)
        if x in counts:
            counts[x] += 1
        else:
            counts[x] = 1

    # Print each team's chances of winning, according to simulation
    for team in sorted(counts, key=lambda team: counts[team], reverse=True):
        win_percentage = counts[team] * 100 / N
        print(f"{team}: {win_percentage:.1f}% chance of winning")


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
    # Simulate rounds until only one team remains
    while len(teams) > 1:
        teams = simulate_round(teams)

    return teams[0]["team"]

if __name__ == "__main__":
    main()
