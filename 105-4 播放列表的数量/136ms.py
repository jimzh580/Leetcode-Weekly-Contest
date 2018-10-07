class Solution:
    def numMusicPlaylists(self, N, L, K):
        """
        :type N: int
        :type L: int
        :type K: int
        :rtype: int
        """
        M = 10**9 + 7
        # ways(t, p) = ways to play p different songs in t time
        # ways(t, p) =   ways(t-1, p-1) * (N-p) [NEW SONG]
        #              + ways(t-1, p) * max(p-K, 0)
        # 1 0 0
        # 0 3
        ways = [1] + [0]*N
        for _ in range(L):
            ways = [0] + [(ways[p-1]*(N-p+1) + ways[p]*max(p-K,0)) % M for p in range(1,N+1)]
        return ways[-1]