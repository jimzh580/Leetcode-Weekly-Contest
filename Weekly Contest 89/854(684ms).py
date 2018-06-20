class Solution:
    def dfs(self, x, cnt):#x为匹配到第几个，cnt为交换次数
        if self.ans is not None and cnt >= self.ans:
            return
        if x == self.n:#匹配完成
            self.ans = cnt
            return

        if self.a[x] == self.b[x]:#匹配成功
            self.dfs(x + 1, cnt)
        else:#尝试交换匹配
            for i in range(x + 1, self.n):
                if self.b[i] == self.a[x]:
                    self.b[x], self.b[i] = self.b[i], self.b[x]
                    self.dfs(x + 1, cnt + 1)
                    self.b[x], self.b[i] = self.b[i], self.b[x]

    def kSimilarity(self, A, B):
        """
        :type A: str
        :type B: str
        :rtype: int
        """
        data = [[p, q] for (p, q) in zip(A, B) if p != q]
        #构造不同二元组集
        self.a = [e[0] for e in data]#a中的不同
        self.b = [e[1] for e in data]#b中的不同
        self.n = len(self.a)#不同的数量
        self.ans = None

        self.dfs(0, 0)
        return self.ans