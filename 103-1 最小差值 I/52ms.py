class Solution:
    def smallestRangeI(self, A, K):
        """
        :type A: List[int]
        :type K: int
        :rtype: int
        """
        if len(A)<=1:return 0
        minn=min(A)
        maxn=max(A)
        if minn+K>=maxn-K:
            return 0
        else:
            return maxn-K-minn-K