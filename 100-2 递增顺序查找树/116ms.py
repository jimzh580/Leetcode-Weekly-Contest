# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def dfs(self, root):
        if root is None:
            return
        self.dfs(root.left)
        self.nodes.append(root)
        self.dfs(root.right)
        
    def increasingBST(self, root):
        """
        :type root: TreeNode
        :rtype: TreeNode
        """
        self.nodes = []
        self.dfs(root)
        for i in range(len(self.nodes)-1):
            self.nodes[i].left = None
            self.nodes[i].right = self.nodes[i+1]
        self.nodes[-1].left = None
        self.nodes[-1].right = None
        return self.nodes[0]