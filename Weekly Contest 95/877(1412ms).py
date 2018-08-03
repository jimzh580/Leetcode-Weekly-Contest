class Solution:
    def stoneGame(self, piles):
        """
        :type piles: List[int]
        :rtype: bool
        """
        f=[[0 for _ in range(len(piles))] for _ in range(len(piles))]
        s=[[0 for _ in range(len(piles))] for _ in range(len(piles))]
        for j in range(len(piles)):
            f[j][j]=piles[j]
            for i in range(j-1,-1,-1):
                f[i][j]=max(piles[i]+s[i+1][j],piles[j]+s[i][j-1])
                s[i][j]=min(f[i+1][j],f[i][j-1])
        return f[0][len(piles)-1]>s[0][len(piles)-1]