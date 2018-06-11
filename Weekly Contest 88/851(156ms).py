from collections import defaultdict
class Solution:
    def dfs(self, x):
        if self.ret[x] is not None:#避免反复搜
            return

        # print(x, self.edge[x])

        self.ret[x] = x#先赋为自身
        for i in self.edge[x]:#在比自己有钱的人里找
            self.dfs(i)#由于传递关系(即比有钱的关系)
            if self.q[self.ret[i]] < self.q[self.ret[x]]:#若更加喧闹
                self.ret[x] = self.ret[i]
                
    def loudAndRich(self, richer, quiet):
        """
        :type richer: List[List[int]]
        :type quiet: List[int]
        :rtype: List[int]
        """
        import collections

        self.q = quiet
        self.n = len(quiet)
        self.edge = [collections.deque() for _ in range(self.n)]#为每人创建队列
        for (p, q) in richer:#记录比自己有钱的人
            self.edge[q].append(p)

        self.ret = [None for _ in range(self.n)]
        for i in range(self.n):
            self.dfs(i)
        return self.ret
        
# richer=[[1,0],[2,1],[3,1],[3,7],[4,3],[5,3],[6,3]]
# quiet = [3,2,5,4,6,1,7,0]
richer=[[0,2],[0,3],[0,4],[0,5],[0,6],[0,8],[0,9],[1,3],[1,4],[1,6],[1,7],[1,9],[2,3],[2,4],[2,5],[2,6],[2,8],[2,9],[3,4],[3,5],[3,6],[3,7],[3,8],[3,9],[4,5],[4,6],[4,7],[4,8],[4,9],[5,6],[5,7],[5,8],[5,9],[6,7],[6,8],[6,9],[7,8],[7,9],[8,9]]
quiet=[0,7,2,9,6,5,1,3,8,4]
print(Solution.loudAndRich('self',richer,quiet))