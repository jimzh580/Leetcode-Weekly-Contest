from collections import defaultdict

class Solution:
    def isNStraightHand(self, hand, W):
        """
        :type hand: List[int]
        :type W: int
        :rtype: bool
        """
        
        n = len(hand)
        if n%W != 0:
            return False
        hand.sort()
        cts = defaultdict(int)
        for v in hand:
            cts[v] += 1
        for v in hand:
            if cts[v] == 0:
                continue
            for j in range(W):
                if cts[v+j] == 0:
                    return False
                cts[v+j] -= 1
        return True