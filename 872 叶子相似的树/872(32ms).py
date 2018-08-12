# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def leafSimilar(self, root1, root2):
        """
        :type root1: TreeNode
        :type root2: TreeNode
        :rtype: bool
        """
        if root1 is None and root2 is None:return False
        
        def mid(path,root):
            if root.left:mid(path,root.left)
            if root.left is None and root.right is None:
                path.append(root.val)
            if root.right:mid(path,root.right)
        
        path1=[]
        path2=[]
        mid(path1,root1)
        mid(path2,root2)
        print(path1,path2)
        return path1==path2