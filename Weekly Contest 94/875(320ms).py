class Solution(object):
    def minEatingSpeed(self, piles, H):
        """
        :type piles: List[int]
        :type H: int
        :rtype: int
        """
        assert len(piles) <= H
        a = 0
        b = max(piles)
        while a + 1 < b:#二分查找
            c = (a + b) // 2
            if sum(1+(p-1)//c for p in piles) <= H: b = c #该方案是否足够小
            else: a = c
        return b