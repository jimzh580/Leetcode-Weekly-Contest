class Solution(object):
    def minIncrementForUnique(self, A):
        """
        :type A: List[int]
        :rtype: int
        """
        A = sorted(A)
        las = -1
        ans = 0
        for x in A:
            if x <= las:
                las += 1
                ans += las - x
            else:
                las = x
        return ans