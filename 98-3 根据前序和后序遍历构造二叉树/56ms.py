# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def constructFromPrePost(self, pre, post):
        """
        :type pre: List[int]
        :type post: List[int]
        :rtype: TreeNode
        """
        def make(s, t):
            if not s: return None
            node = TreeNode(s[0])
            if len(s) == 1:
                return node

            i = 0
            while t[i] != s[1]: i += 1
            node.left = make(s[1:i+2], t[:i+1])
            node.right = make(s[i+2:], t[i+1:])
            return node    
        
        return make(pre, post)