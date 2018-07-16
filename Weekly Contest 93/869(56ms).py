class Solution:
    def reorderedPowerOf2(self, N):
        """
        :type N: int
        :rtype: bool
        """
        if N == 1:
            return True
        d1 = list(sorted(str(N)))
        for i in range(1, 33):
            d2 = list(sorted(str(1 << i)))
            if d1 == d2:
                return True
        return False