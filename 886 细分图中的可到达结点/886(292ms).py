from heapq import heappush, heappop

class Solution:
    def reachableNodes(self, edges, M, N):
        """
        :type edges: List[List[int]]
        :type M: int
        :type N: int
        :rtype: int
        """
        es = [{} for _ in range(N)]
        for i, j, n in edges:
            es[i][j] = [n, 0]
            es[j][i] = [n, 0]
        
        ans = 0
        pq = [(-M, 0)]
        v = [False] * N
        while pq:
            r, i = heappop(pq)
            r = -r
            if v[i]: continue
            v[i] = True
            
            ans += 1
            for j, x in es[i].items():
                delta = min(r, x[0] - es[j][i][1])
                ans += delta
                x[1] = delta
                if r > x[0] and not v[j]:
                    heappush(pq, (x[0]+1-r,j))
        return ans