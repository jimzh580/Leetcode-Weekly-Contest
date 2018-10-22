class Solution:
    def minMalwareSpread(self, graph, initial):
        """
        :type graph: List[List[int]]
        :type initial: List[int]
        :rtype: int
        """
        initial.sort()
        edge=collections.defaultdict(list)
        for i in range(len(graph)):
            for j in range(len(graph)):
                if i!=j and graph[i][j]:
                    edge[i].append(j)
                    
                    
        def dfs(i,vis):
            for j in edge[i]:
                if j!=self.no and j not in vis:
                    vis.add(j)
                    dfs(j,vis)
            
        minn=len(graph)
        ans=-1
        for i in initial:
            self.no=i
            vis=set()
            for j in initial:
                if i==j:continue
                dfs(j,vis)
            vis|=set(initial)
            vis.remove(i)
            if len(vis)<minn:
                minn=len(vis)
                ans=i
        return ans