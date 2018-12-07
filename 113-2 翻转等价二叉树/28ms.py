# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def flipEquiv(self, root1, root2):
        """
        :type root1: TreeNode
        :type root2: TreeNode
        :rtype: bool
        """
        if(not root1 and not root2): return True
        if(not root1 or not root2):return False
        if(root1.val!=root2.val): return False
        
        def valid(root1,root2):
            if(not root1 or not root2):
                return root1==root2
            return root1.val==root2.val and \
            ((valid(root1.left,root2.left) and valid(root1.right,root2.right)) or \
             (valid(root1.left,root2.right) and valid(root1.right,root2.left)))
        
        return valid(root1,root2)