class DSU(object):
    def __init__(self, n):
        self.par = range(n)
        self.sz = [1] * n

    def find(self, x):
        if self.par[x] != x:
            self.par[x] = self.find(self.par[x])
        return self.par[x]

    def union(self, x, y):
        xr, yr = self.find(x), self.find(y)
        if xr == yr:
            return
        if self.sz[xr] < self.sz[yr]:
            xr, yr = yr, xr
        self.par[yr] = xr
        self.sz[xr] += self.sz[yr]


class Solution(object):
    def regionsBySlashes(self, grid):
        """
        :type grid: List[str]
        :rtype: int
        """
        n = len(grid)
        dsu = DSU(n * n * 4)
        for i in range(n):
            for j in range(n):
                t = grid[i][j]
                index = (i * n + j) * 4
                if t == '/':
                    dsu.union(index, index + 1)
                    dsu.union(index + 2, index + 3)
                elif t == '\\':
                    dsu.union(index, index + 3)
                    dsu.union(index + 1, index + 2)
                else:
                    dsu.union(index, index + 1)
                    dsu.union(index + 2, index)
                    dsu.union(index, index + 3)
                if i > 0:
                    dsu.union(index + 1, index - n * 4 + 3)
                if j > 0:
                    dsu.union(index, index - 4 + 2)

        h = set()
        for i in range(n * n * 4):
            h.add(dsu.find(i))
        return len(h)