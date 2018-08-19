# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def distanceK(self, root, target, K):
        """
        :type root: TreeNode
        :type target: TreeNode
        :type K: int
        :rtype: List[TreeNode]
        """
        edges = collections.defaultdict(list)
        nodes = {}
        
        def make_graph(node):#建立无向图
            if node.left:
                edges[node].append(node.left)
                edges[node.left].append(node)
                make_graph(node.left)
            if node.right:
                edges[node].append(node.right)
                edges[node.right].append(node)
                make_graph(node.right)
        
        make_graph(root)
        ans = []
        q = [target]#队列
        seen = set(q)#已查
        
        for _ in range(K):#从目标节点宽度搜索扩展K次即可
            if not q: break#为空
            q2 = []
            for i in q:#扩展
                for j in edges[i]:
                    if j not in seen:
                        seen.add(j)
                        q2.append(j)
            q = q2
        return [x.val for x in q]