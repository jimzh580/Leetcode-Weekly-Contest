class Solution:
    def binaryGap(self, N):
        """
        :type N: int
        :rtype: int
        """
        seen = False
        n = 0
        r = 0
        while N > 0:
            
            if N & 1 == 1:
                if not seen:
                    seen = True
                else:
                    r = max(r, n)
                    n = 0
            N >>= 1
            if seen:
                n += 1
        return r