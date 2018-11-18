class Solution(object):
    def minDeletionSize(self, A):
        """
        :type A: List[str]
        :rtype: int
        """
        if A==[] or A[0]=="":return 0
        res=0
        for i in range(len(A[0])):
            for j in range(1,len(A)):
                if ord(A[j][i])<ord(A[j-1][i]):
                    res+=1
                    break
        return res