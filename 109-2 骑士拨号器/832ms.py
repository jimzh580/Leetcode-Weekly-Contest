class Solution(object):
    def knightDialer(self, N):
        """
        :type N: int
        :rtype: int
        """
        M = 10**9 + 7
        t = [[4, 6], [6, 8], [7, 9], [4, 8], [0, 3, 9], [], [0, 1, 7], [2, 6], [1, 3], [2, 4]]
        ways = [1] * 10
        for _ in xrange(1, N):
            ways2 = [0] * 10
            for i in xrange(10):
                for j in t[i]:
                    ways2[j] = (ways2[j] + ways[i]) % M
            ways = ways2
            
        return sum(ways) % M