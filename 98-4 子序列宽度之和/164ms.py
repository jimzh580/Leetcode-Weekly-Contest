class Solution(object):
    def sumSubseqWidths(self, A):
        """
        :type A: List[int]
        :rtype: int
        """
        MOD = 10**9 + 7
        A.sort()
        n = len(A)
        pow2 = [1]
        for _ in range(n+1):
            pow2.append(pow2[-1] * 2 % MOD)
        
        ans = 0
        for i, a in enumerate(A):
            ans -= a * (pow2[n-i-1] - 1) % MOD
            ans += a * (pow2[i] - 1) % MOD
            ans = (ans + MOD) % MOD
        return ans