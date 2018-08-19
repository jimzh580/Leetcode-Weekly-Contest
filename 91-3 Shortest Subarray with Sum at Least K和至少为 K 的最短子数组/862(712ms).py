class Solution:
    def shortestSubarray(self, A, K):
        """
        :type A: List[int]
        :type K: int
        :rtype: int
        """
        ps = [0]
        for a in A:#建立累加数组
            ps.append(a + ps[-1])
        
        INF = len(ps)
        ans = INF
        q = collections.deque()#建立队列
        for i in range(len(ps)):
            while q and ps[i] - ps[q[0]] >= K:
                ans = min(ans, i - q[0])
                q.popleft()
            while q and ps[i] <= ps[q[-1]]:
                q.pop()
            q.append(i)
        return ans if ans < INF else -1