class Solution(object):
    def surfaceArea(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        if not grid or not grid[0]: return 0
        s,m,n=0,len(grid)+1,len(grid[0])+1
        grid.append([0]*(n-1))
        for x in grid: x.append(0)
        for i in range(m):
            for j in range(n):
                if grid[i][j]: s+=2
                s+=abs(grid[i-1][j]-grid[i][j])+abs(grid[i][j-1]-grid[i][j])
        return s