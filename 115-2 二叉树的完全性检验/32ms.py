# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
def count_tree(root):
    if root is None:
        return 0
    else:
        return 1 + count_tree(root.left) + count_tree(root.right)

class Solution(object):
    def isCompleteTree(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        n = count_tree(root)
        l = [root]
        count = 1
        while l:
            nl = []
            for node in l:
                if node.left is None:
                    return count == n
                nl.append(node.left)
                count += 1
                if node.right is None:
                    return count == n
                nl.append(node.right)
                count += 1
            l = nl