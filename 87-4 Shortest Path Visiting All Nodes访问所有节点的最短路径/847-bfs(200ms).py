from collections import deque,defaultdict
class Solution(object):
    def shortestPathLength(self, graph):
        N = len(graph)
        queue = deque((1 << x, x) for x in range(N))
        dist = defaultdict(lambda: N*N)#默认取值为N平方
        for x in range(N): dist[1 << x, x] = 0

        while queue:
            cover, head = queue.popleft()
            d = dist[cover, head]#d计算长度
            if cover == 2**N - 1: return d#到达终态
            for child in graph[head]:
                cover2 = cover | (1 << child)#状态标识
                if d + 1 < dist[cover2, child]:#选取最小的路径长度
                    dist[cover2, child] = d + 1
                    queue.append((cover2, child))
                    
graph=[[1,2,3],[0],[0],[0]]
print(Solution.shortestPathLength('self',graph))