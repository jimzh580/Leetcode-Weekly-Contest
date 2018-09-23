class Solution:
    def snakesAndLadders(self, board):
        """
        :type board: List[List[int]]
        :rtype: int
        """
        p = []
        for i, row in enumerate(reversed(board)):#恢复正常顺序
            p.extend(reversed(row) if i%2 else row)

        seen = [False for _ in p]#判断循环
        target = len(p) - 1 #目标值
        q = set([0]) 
        d = 0
        def moves(i):
            for j in range(i+1, i+7):
                if j > target: break
                if p[j] > 0: yield p[j] - 1 #有梯
                else: yield j #爬坡
                
        while q:
            if target in q: return d #到达
            for i in q: seen[i] = True #标记
            q = set([j
                     for i in q
                     for j in moves(i)
                     if not seen[j]])
            d += 1
        return -1