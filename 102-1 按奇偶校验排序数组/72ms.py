class Solution(object):
    def sortArrayByParity(self, A):
        """
        :type A: List[int]
        :rtype: List[int]
        """
        i=0
        j=len(A)-1
        while i<j:
            while i<j and A[i]&1==0:
                i+=1
            while i<j and A[j]&1:
                j-=1
            if i<j:
                A[i],A[j]=A[j],A[i]
        return A