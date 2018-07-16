class Solution:
    def advantageCount(self, A, B):
        """
        :type A: List[int]
        :type B: List[int]
        :rtype: List[int]
        """
        n = len(A)
        A = list(sorted(A))
        b = [(v, i) for i, v in enumerate(B)]#(值，下标)
        b.sort()#按值排序
        r = [-1] * n #结果
        used = [False] * n #已被用过的
        i = 0
        for v, j in b:
            while i < n and A[i] <= v: #A中小于当前v的
                i += 1
            if i < n:#贪心，选取当前仅仅大于v的值
                r[j] = A[i]
                used[i] = True
                i += 1
        i = 0
        for j in range(n):#余下的就算亏也得匹配
            if used[j]: continue#已用过
            while r[i] >=0:#已有匹配
                i += 1
            r[i] = A[j]
            i += 1
        return r