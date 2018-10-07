class Solution:
    def maxSubarraySumCircular(self, A):
        """
        :type A: List[int]
        :rtype: int
        """
        if not A: return 0
        m = [A[-1]] * len(A)
        r = float('-inf')
        s = 0
        for i in range(len(A)-1,-1,-1):#后往前的最大子和
            s += A[i]
            r = max(r, s)
            m[i] = r

        r = float('-inf')
        s = v = 0
        for x in A:#正常前往后的最大子和
            s += x
            r = max(r, s - v)
            v = min(v, s)

        s = 0
        for i in range(len(A) - 1):
            s += A[i]
            r = max(r, s + m[i+1])
        return r