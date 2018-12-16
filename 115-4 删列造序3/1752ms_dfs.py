class Solution(object):
    def minDeletionSize(self, A):
        """
        :type A: List[str]
        :rtype: int
        """
        m = len(A)
        n = len(A[0])
        memo = dict()
        def dfs(j, s):
            if j == n:
                return 0
            if (j, s) not in memo:
                found = False
                for i in range(m):
                    char = A[i][j]
                    if char < s[i]:
                        found = True
                if found:
                    memo[j, s] = dfs(j+1, s) + 1
                else:
                    skeep = ''
                    for i in range(m):
                        skeep += max(s[i], A[i][j])
                    memo[j, s] = min(dfs(j + 1,s) + 1, dfs(j+1, skeep))
            return memo[j, s]
        return dfs(0, 'a' * m)