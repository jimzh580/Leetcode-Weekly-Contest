class Solution:
    def numMagicSquaresInside(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        n=len(grid)
        ans=0
        def isvalid(x1,x2,x3,y1,y2,y3,z1,z2,z3):
            if x1+x2+x3==y1+y2+y3==z1+z2+z3 ==\
            x1+y1+z1==x2+y2+z2==x3+y3+z3 ==\
            x1+y2+z3==x3+y2+z1 and \
            1<=x1<=9 and 1<=x2<=9 and 1<=x3<=9\
            and 1<=y1<=9 and 1<=y2<=9 and 1<=y3<=9\
            and 1<=z1<=9 and 1<=z2<=9 and 1<=z3<=9\
            and x1!=x2!=x3!=y1!=y2!=y3!=z1!=z2!=z3:
                return True
            return False
        for i in range(n-2):
            for j in range(n-2):
                if isvalid(grid[i][j],grid[i][j+1],grid[i][j+2],\
                grid[i+1][j],grid[i+1][j+1],grid[i+1][j+2],
                grid[i+2][j],grid[i+2][j+1],grid[i+2][j+2]):
                    ans+=1
        return ans
        
grid=[[10,3,5],[1,6,11],[7,9,2]]
print(Solution.numMagicSquaresInside('self',grid))