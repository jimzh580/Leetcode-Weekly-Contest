class Solution:
    def transpose(self, A):
        """
        :type A: List[List[int]]
        :rtype: List[List[int]]
        """
        if A==[]:return []
        return [[A[i][j] for i in range(len(A))] for j in range(len(A[0]))]
        
A=[[1]]
print(Solution.transpose('self',A))