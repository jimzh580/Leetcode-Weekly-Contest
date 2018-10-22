class Solution:
    def threeEqualParts(self, A):
        """
        :type A: List[int]
        :rtype: List[int]
        """
        a = A
        n = len(a)
        s = sum(a)
        #每一部分应该拥有相同数量的1
        if s % 3 != 0:
            return [-1, -1]
        if s == 0:
            return [0, 2]

        idx = []
        for i in range(n):
            if a[i] == 1:
                idx.append(i)

        i = idx[0]
        j = idx[s // 3]
        k = idx[s // 3 + s // 3]

        while k < n:
            if not (a[i] == a[j] == a[k]):
                return [-1, -1]
            if i == idx[s // 3] or j == idx[s // 3 + s // 3]:
                return [-1, -1]
            i += 1
            j += 1
            k += 1
        if i <= idx[s // 3 - 1] or j <= idx[s // 3 + s // 3 - 1]:
            return [-1, -1]
        
        return [i - 1, j]





