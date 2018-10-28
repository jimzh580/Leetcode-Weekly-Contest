class Solution:
    def minFallingPathSum(self, A):
        """
        :type A: List[List[int]]
        :rtype: int
        """
        n = len(A)
        dp = A[0][::]
        for row in A[1:]:
            ndp = row[::]
            
            for i in range(n):
                candidates = [dp[i]]
                if i:
                    candidates.append(dp[i-1])
                if i != n-1:
                    candidates.append(dp[i+1])
                ndp[i] += min(candidates)
            dp = ndp
        return min(dp)