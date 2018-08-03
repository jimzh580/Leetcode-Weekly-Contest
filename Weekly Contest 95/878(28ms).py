class Solution(object):
    def gcd(self, a, b):
        if 0 == b:
            return a
        return self.gcd(b, a % b)
    
    def nthMagicalNumber(self, n, a, b):
        """
        :type N: int
        :type A: int
        :type B: int
        :rtype: int
        """
        c = a * b / self.gcd(a, b)
        lo, hi = 1, 1 << 60
        while lo < hi:
            mid = (lo + hi) / 2
            t = mid / a + mid / b - mid / c
            if t < n:
                lo = mid + 1
            else:
                hi = mid
        return int(lo) % 1000000007