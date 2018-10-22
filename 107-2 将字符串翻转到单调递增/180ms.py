class Solution:
    def minFlipsMonoIncr(self, S):
        """
        :type S: str
        :rtype: int
        """
        a = [int(e) for e in S]
        n = len(a)
        z = [None for _ in range(n)]
        o = [None for _ in range(n)]

        z[0] = 1 if a[0] == 0 else 0
        o[0] = 1 if a[0] != 0 else 0
        for i in range(1, n):
            if a[i] == 0:
                z[i] = z[i - 1] + 1
                o[i] = o[i - 1]
            else:
                z[i] = z[i - 1]
                o[i] = o[i - 1] + 1

        ans = min(sum(a), n - sum(a))
        for i in range(n - 1):
            #前面为1的需要修改，后面为0的也需要修改
            ans = min(ans, o[i] + (z[n - 1] - z[i]))
        return ans