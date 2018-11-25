class Solution(object):
    def minIncrementForUnique(self, A):
        """
        :type A: List[int]
        :rtype: int
        """
        if A==[]:return 0
        A.sort()
        minn=A[0]
        ans=0
        l=len(A)
        for i in range(1,l):
            if A[i]<=minn:
                ans+=minn+1-A[i]
                minn+=1
            else:
                minn=A[i]
                
        return ans