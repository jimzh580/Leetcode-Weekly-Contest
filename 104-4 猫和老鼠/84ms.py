class Solution:
    def catMouseGame(self, graph):
        """
        :type graph: List[List[int]]
        :rtype: int
        """
        memo = {} #模拟记录法
        def move(ci, mi, mt):#猫位置，鼠位置，谁移动
            key = (ci, mi, mt)
            if key in memo:
                return memo[key]
            memo[key] = 0
            if not mt: #cats turn
                for nxtmove in graph[ci]:#判断能否捕捉
                    if nxtmove == mi:#捉住老鼠
                        memo[key] = 2
                        return 2
                res = 1
                for nxtmove in graph[ci]:#尝试移动
                    if nxtmove == 0:
                        continue
                    tmp = move(nxtmove, mi, True)
                    if tmp == 2:
                        res =2
                        break
                    if tmp == 0:
                        res = 0
                memo[key] = res
                return res
            #mouse True
            for nxtmove in graph[mi]:
                if nxtmove == 0:#能否成功到达洞
                    memo[key] = 1
                    return 1
            res = 2
            for nxtmove in graph[mi]:#尝试移动     
                if nxtmove != ci:
                    tmp = move(ci, nxtmove, False)
                    if tmp == 1:
                        res = 1
                        break
                    if tmp == 0:
                        res = 0
            memo[key] = res
            return res
        return move(2, 1, True)