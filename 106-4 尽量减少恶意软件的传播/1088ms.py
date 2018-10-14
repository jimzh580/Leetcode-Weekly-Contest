class Solution:
    
    def expand(self, exclude):
        self.visited = set()
        for i in self.initial:
            if i == exclude:
                continue
            self.dfs(i)
        return len(self.visited)
    
    def dfs(self, cur):
        if cur in self.visited:
            return
        self.visited.add(cur)
        for to in self.graph[cur]:
            self.dfs(to)
            
        
    def minMalwareSpread(self, graph, initial):
        """
        :type graph: List[List[int]]
        :type initial: List[int]
        :rtype: int
        """
        initial.sort()
        for i in range(len(graph)):
            graph[i] = [j for j in range(len(graph)) if graph[i][j]]
        self.graph = graph
        
        self.initial = initial
        best = len(graph)+10
        ans = -1
        for i in range(len(initial)):
            this = self.expand(exclude = initial[i])
            # print this, initial[i]
            if this < best:
                best = this
                ans = initial[i]
        return ans