class Solution(object):
    def totalFruit(self, tree):
        """
        :type tree: List[int]
        :rtype: int
        """
        b0, b1, p0, p1 = [-1] * 4
        ret, la = 0, 0
        for i, t in enumerate(tree):
            if t == b0:
                p0 = i
            elif t == b1:
                p1 = i
            else:
                if p1 < p0:
                    b0, p0, b1, p1 = b1, p1, b0, p0
                b0, p0, la = t, i, p0+1
            ret = max(ret, i-la+1)
        return ret