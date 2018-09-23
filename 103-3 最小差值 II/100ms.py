class Solution:
    def smallestRangeII(self, A, K):
        """
        :type A: List[int]
        :type K: int
        :rtype: int
        """
        # assume everything already -K so we pick some to +2K
        if not A: return 0
        A = sorted(set(A))
        K *= 2
        m = A[-1]
        r = A[-1] - A[0]
        for i in range(len(A)-1):
            if A[i] >= A[0] + K: break #比最小值+k大，后面的必然是不需改变了
            m = max(m, A[i] + K) #更新最大值
            r = min(r, m - min(A[i+1], A[0] + K)) #更新最小差距
        return r