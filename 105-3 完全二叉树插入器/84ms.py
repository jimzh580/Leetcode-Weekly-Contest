# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class CBTInserter:

    def __init__(self, root):
        """
        :type root: TreeNode
        """
        self.nodes = []
        q = [root]
        while q:
            self.nodes.extend(q)
            q = [c for n in q for c in (n.left,n.right) if c]

    def insert(self, v):
        """
        :type v: int
        :rtype: int
        """
        i = len(self.nodes)
        self.nodes.append(TreeNode(v))
        j = (i-1) // 2
        if i % 2: self.nodes[j].left = self.nodes[i]
        else: self.nodes[j].right = self.nodes[i]
        return self.nodes[j].val

    def get_root(self):
        """
        :rtype: TreeNode
        """
        return self.nodes[0]


# Your CBTInserter object will be instantiated and called as such:
# obj = CBTInserter(root)
# param_1 = obj.insert(v)
# param_2 = obj.get_root()