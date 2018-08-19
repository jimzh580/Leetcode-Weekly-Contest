class Solution:
    def consecutiveNumbersSum(self, N):
        """
        :type N: int
        :rtype: int
        """
        def ok(n,k):
            u=n//k
            v=u-k+1
            if v&1:return False
            return v>0

        N*=2
        d=0
        k=1
        while k*k<=N:
            if N%k==0:
                if ok(N, k):d+=1
                if k*k<N and ok(N, N//k):d+=1
            k+=1
        return d

print(Solution.consecutiveNumbersSum('self',15 ))