class Solution:
    def sumOfDistancesInTree(self, N, edges):
        """
        :type N: int
        :type edges: List[List[int]]
        :rtype: List[int]
        """
        graph = collections.defaultdict(set)
        for u, v in edges:
            graph[u].add(v)
            graph[v].add(u)

        count = [1] * N
        ans = [0] * N
        def dfs(node = 0, parent = None):
            for nei in graph[node]:
                if nei != parent:
                    dfs(nei, node)
                    count[node] += count[nei]
                    ans[node] += ans[nei] + count[nei]

        def dfs2(node = 0, parent = None):
            for nei in graph[node]:
                if nei != parent:
                    ans[nei] = ans[node] - count[nei] + N - count[nei]
                    dfs2(nei, node)

        dfs()
        dfs2()
        return ans