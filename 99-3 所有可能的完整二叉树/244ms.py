# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def allPossibleFBT(self, N):
        """
        :type N: int
        :rtype: List[TreeNode]
        """
        if N%2==0: return []
        if N==1: return [TreeNode(0)]
        s=[]
        for i in range(1,N-1,2):
            l,r=self.allPossibleFBT(i),self.allPossibleFBT(N-i-1)
            for ll in l:
                for rr in r:
                    p=TreeNode(0)
                    p.left=ll
                    p.right=rr
                    s.append(p)
        return s