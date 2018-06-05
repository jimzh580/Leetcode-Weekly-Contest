class Solution():
    def shortestPathLength(self, graph):
        N = len(graph)
        dist = [[float('inf')] * N for i in range(1 << N)]
        for x in range(N):#从自身到自身
            dist[1<<x][x] = 0

        for cover in range(1 << N):#每种状态的枚举
            repeat = True
            while repeat:
                repeat = False
                for head, d in enumerate(dist[cover]):
                    for nei in graph[head]:#通路
                        cover2 = cover | (1 << nei)#状态标识
                        if d + 1 < dist[cover2][nei]:
                            dist[cover2][nei] = d + 1
                            if cover == cover2:
                                repeat = True

        return min(dist[2**N - 1])
        
graph=[[1,2,3],[0],[0],[0]]
print(Solution.shortestPathLength('self',graph))