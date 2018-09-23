from collections import Counter

class TopVotedCandidate:

    def __init__(self, persons, times):
        """
        :type persons: List[int]
        :type times: List[int]
        """
        self.times = times
        self.winners = []
        best = 0
        votes = Counter()
        winner = 0
        for p in persons:
            votes[p] += 1
            if votes[p] >= best:
                best = votes[p]
                winner = p
            self.winners.append(winner)

    def q(self, t):
        """
        :type t: int
        :rtype: int
        """
        a = 0
        b = len(self.winners)
        while a + 1 < b:
            c = (a + b) // 2
            if self.times[c] <= t: a = c
            else: b = c
        return self.winners[a]


# Your TopVotedCandidate object will be instantiated and called as such:
# obj = TopVotedCandidate(persons, times)
# param_1 = obj.q(t)