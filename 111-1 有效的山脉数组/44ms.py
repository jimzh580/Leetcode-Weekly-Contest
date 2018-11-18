class Solution(object):
    def validMountainArray(self, A):
        """
        :type A: List[int]
        :rtype: bool
        """
        if len(A)<3:return False
        left=0
        for i in range(1,len(A)):
            if A[i]>A[i-1]:
                left=i
            elif A[i]==A[i-1]:
                return False
            else:
                break
        if left>=len(A)-1 or left==0:return False
        
        for i in range(left,len(A)-1):
            if A[i]<=A[i+1]:
                return False
            
        return True