class Solution:
    def projectionArea(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        n, m = len(grid), len(grid[0])
        ans = 0
        
        for i in range(n):#底面
            for j in range(n):
                if grid[i][j]:
                    ans += 1
        
        for i in range(n):
            ans += max(grid[i])
        
        for j in range(m):
            ans += max([grid[i][j] for i in range(n)])
        
        return ans