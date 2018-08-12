class Solution(object):
    def lenLongestFibSubseq(self, A):
        """
        :type A: List[int]
        :rtype: int
        """
        if len(A) < 3: return 0
        s = set(A)
        def f(i, j):
            r = 2
            a = A[i]
            b = A[j]
            while a + b in s: a, b, r = b, a + b, r + 1
            return r
        r = max(f(i, j) for j in xrange(1, len(A)) for i in xrange(j))
        return r if r >= 3 else 0