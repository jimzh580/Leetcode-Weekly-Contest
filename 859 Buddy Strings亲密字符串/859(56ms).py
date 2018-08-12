class Solution:
    def buddyStrings(self, A, B):
        """
        :type A: str
        :type B: str
        :rtype: bool
        """
        if A=='' or B=='':return False
        a=b=-1
        for i in range(len(A)):
            if A[i]!=B[i]:
                if a==-1:
                    a=i
                elif b==-1:
                    b=i
                else:
                    return False
        if a==b==-1:
            if len(list(set(A)))==len(A):return False
            else:return True
        if A[a]==B[b] and A[b]==B[a]:return True
        else:return False
        
A = "aa"
B = "aa"
print(Solution.buddyStrings('self',A,B))