class Solution(object):
    def isMonotonic(self, A):
        """
        :type A: List[int]
        :rtype: bool
        """
        if len(A)<=2:return True
        a=[A[i]-A[i-1] for i in range(1,len(A))]
        return len(list(filter(lambda x:x>=0,a)))==len(a) or\
            len(list(filter(lambda x:x<=0,a)))==len(a)