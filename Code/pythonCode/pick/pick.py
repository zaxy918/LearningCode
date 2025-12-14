import random
import math


class Team:

    def __init__(
        origin_strength: float,
        win_prob: list,
        last_comp_res: bool,
        competitor_cnt: dict,
    ):
        self.origin_strength = origin_strength  # Team strength, from 0.0 to 1.0
        self.strength = (
            origin_strength  # Current strength, updated after each competition
        )
        self.inc_ratio = 1 / math.log1p(
            origin_strength * 100
        )  # Increment ratio for strength increase
        self.win_prob = (
            win_prob  # Probability of winning against other teams, indexed by team_id
        )
        self.last_comp_res = (
            last_comp_res  # Result of the last competition, True if won, False if lost
        )
        self.competitor_cnt = (
            competitor_cnt  # Count of competitors in each category, indexed by team_id
        )

    def win(self, other: "Team"):
        # Update the last competition result
        self.last_comp_res = True
        other.last_comp_res = False
        # Update the strength
        self.__update_strength()
        other.__update_strength()

    def __update_strength(self):
        if self.last_comp_res:
            self.strength += random.uniform(0.4, 0.9) * self.inc_ratio
            if self.strength > 1.0:
                self.strength = 1.0
        else:
            self.strength += random.uniform(0.2, 0.7) * self.inc_ratio
            if self.strength > 1.0:
                self.strength = 1.0
        self.inc_ratio = 1 / math.log1p(self.strength * 100)


def init_win_prob(teams: list):
    pass


def update_win_prob(teams: list):
    teams_num = len(teams)
    for i in range(teams_num):
        for j in range(i):
            if i != j:
                prob = teams[i].strength / (teams[i].strength + teams[j].strength)
                prob_matrix[i][j] = prob
                prob_matrix[j][i] = 1 - prob
                teams[i].win_prob[j] = prob
                teams[j].win_prob[i] = 1 - prob


def init_team(team_num: int) -> list:
    teams = []
    for i in range(team_num):
        strength = random.uniform(0.2, 0.7)
        last_comp_res = False
        competitor_cnt = {j: 0 for j in range(team_num) if j != i}
        team = Team(i, strength, [], last_comp_res, competitor_cnt)
        teams.append(team)
    init_win_prob(teams)
    return teams


def compete(teamA: Team, teamB: Team):
    probA = teamA.win_prob[teamB.team_id]
    rand_val = random.uniform(0.0, 1.0)
    if rand_val < probA:
        teamA.win(teamB)
    else:
        teamB.win(teamA)
    update_win_prob([teamA, teamB])


# Competing rules:
# 1. 2n teams compete in n courts. (n must be even)
# 2. Every round, each team competes twice.
# 3. In odd round i, team[i - 1] competes with team[i] in court[(i - 1) / 2].
#     Then the winner of court[(i - 1) / 2] competes with the winner of court[(i + 1) / 2].
#     The loser of court[(i - 1) / 2] competes with the loser of court[(i + 1) / 2].
#     Then the winners of each court stay in court[(i - 1) / 2], and the losers move to court[(i + 1) / 2].
# 4. In even round i, team[i - 1] competes with team[i] in court[(i / 2) - 1].(The team[0] and team[2n - 1] do not compete)
#     Then the winner of court[(i / 2) - 1] competes with the winner of court[i / 2].
#     The loser of court[(i / 2) - 1] competes with the loser of court[i / 2].
#     Then the winners of each court stay in court[(i / 2) - 1], and the losers move to court[i / 2].
# 5. After 2n rounds, the competition ends.
def compete(teams: list):
    random.shuffle(teams)
    teams_num = len(teams)


def output_logs(file: str, teams: list):
    pass


if __name__ == "__main__":
    teams = init_team(16)
    for _ in range(16):
        compete(teams)
    output_logs("./competition_logs.txt", teams)
