class Solution(object):
    def superEggDrop(self, K, N):
        """
        :type K: int
        :type N: int
        :rtype: int
        """
        if N<1 or K<1:return 0
        def log2n(n):
            res=-1
            while n!=0:
                res+=1
                n>>=1
            return res
        bstimes=log2n(N)+1
        if K>=bstimes:return bstimes
        dp=[0 for _ in range(K)]
        res=0
        while True:
            res+=1
            previous=0
            for i in range(0,K):
                tmp=dp[i]
                dp[i]=dp[i]+previous+1
                previous=tmp
                if dp[i]>=N:
                    return res
        