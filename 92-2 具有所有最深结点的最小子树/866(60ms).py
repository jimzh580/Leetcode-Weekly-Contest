# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def mxdep(self, root):#搜索并给每个节点赋予深度值
        if root is None:
            return -1
        v = 1 + max([self.mxdep(node) for node in (root.left, root.right)])
        root.mxd = v
        return v
    
    def subtreeWithAllDeepest(self, root):
        """
        :type root: TreeNode
        :rtype: TreeNode
        """
        mx = self.mxdep(root)
        cur = root
        while True:#开始遍历
            if cur.left is None:
                if cur.right is None:
                    return cur #左右孩子皆为空
                cur = cur.right #左空右不空则到右
            elif cur.right is None:
                cur = cur.left #左不空右空则到左
            else:#都不为空
                if cur.left.mxd > cur.right.mxd:
                    cur = cur.left
                elif cur.left.mxd < cur.right.mxd:
                    cur = cur.right
                else:
                    return cur