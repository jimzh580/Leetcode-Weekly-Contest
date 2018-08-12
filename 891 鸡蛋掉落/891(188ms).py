class Solution:
    def superEggDrop(self, K, N):
        """
        :type K: int
        :type N: int
        :rtype: int
        """
        if K == 1:
            return N
        
        f = [collections.defaultdict(int) for i in range(N+5)]
        for i in range(1, N+5):
            for j in range(K):
                f[i][j] = f[i-1][j-1] + f[i-1][j] + 1
            if max(f[i].values()) >= N:
                return i