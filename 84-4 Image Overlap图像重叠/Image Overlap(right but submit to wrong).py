class Solution:
    def largestOverlap(self, A, B):
        """
        :type A: List[List[int]]
        :type B: List[List[int]]
        :rtype: int
        """
        m = 0
        aa = [0] * (len(A) ** 2)
        bb = []
        
        for t in A:
            aa += t

        aa += [0] * (len(A) ** 2 + 2)
        #aa用作模拟移动
        #print(aa)
        for t in B:
            bb += t
        
        def check(a, b):
            t = 0
            for j in range(len(b)):
                if a[j] == b[j] == 1:
                    t += 1
            return t
            
        for i in range(2 * len(bb) + 1):
            m = max(m, check(aa[i:], bb))
        
        return m

A=[[0,1],[1,1]]
B=[[1,1],[1,1]]
print(Solution.largestOverlap('self',A,B))