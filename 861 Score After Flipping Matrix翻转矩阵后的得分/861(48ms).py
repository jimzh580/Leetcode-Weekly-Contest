class Solution:
    def matrixScore(self, A):
        """
        :type A: List[List[int]]
        :rtype: int
        """
        n,m = len(A),len(A[0])
        for row in A:#贪心，让第一位为1则最大
            if row[0] == 0:
                for i in range(len(row)):
                    row[i] = 1 - row[i]
        ans = n
        for j in range(1, m):#对于每一列
            cnt0 = len([A[i][j] for i in range(n) if A[i][j] == 0])
            ans <<= 1
            ans += max(cnt0, n-cnt0)#分配法
        return ans