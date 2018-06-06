class Solution:
    def shortestPathLength(self, graph):
        """
        :type graph: List[List[int]]
        :rtype: int
        """
        
        def helper(target, status, i):
            if status == target:#到达终态开始回溯计算路径长度
                return 0         
            mem[(status,i)] = -1#当前根节点
            best = float("inf")
            for j in graph[i]:
                temp = status|(1<<j)#状态标识
                if (temp,j) in mem:#形成回路
                    if mem[(temp,j)] != -1:#不为当前根节点
                        best = min(best, mem[(temp,j)])
                else:#继续扩展
                    best = min(best, helper(target,temp,j))
            best += 1
            if best != float("inf"):
                mem[(status, i)] = best
            else:
                del mem[(status,i)]
            
            return best
                    
        nNode = len(graph)
        target = 2 ** nNode - 1#终结状态
        mem = {}
        best = float("inf")
        for i in range(nNode):#枚举从每个节点开始
            best = min(best, helper(target,1 << i,i))
        return best
        
graph=[[1,2,3],[0],[0],[0]]
print(Solution.shortestPathLength('self',graph))