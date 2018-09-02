# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def increasingBST(self, root):
        """
        :type root: TreeNode
        :rtype: TreeNode
        """
        if root is None:return None
        l=[]
        def mid(root):
            if root.left:
                mid(root.left)
            l.append(root.val)
            if root.right:
                mid(root.right)
        mid(root)
        p=head=TreeNode(l[0])
        for i in range(1,len(l)):
            p.right=TreeNode(l[i])
            p=p.right
        return head