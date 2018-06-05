class Solution:
    def longestMountain(self, A):
        """
        :type A: List[int]
        :rtype: int
        """
        n = len(A)
        dl, dr = [1] * n, [1] * n
        for i in range(1, n):
            if A[i] > A[i - 1]:
                dl[i] = dl[i - 1] + 1
        for i in range(n - 2, -1, -1):
            if A[i] > A[i + 1]:
                dr[i] = dr[i + 1] + 1
        ans = 0
        for i in range(n):
            le = dl[i] + dr[i] - 1
            if dl[i] >= 2 and dr[i] >= 2 and le > ans:
                ans = le
        return ans