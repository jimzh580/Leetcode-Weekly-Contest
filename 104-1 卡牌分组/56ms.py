class Solution:
    def hasGroupsSizeX(self, deck):
        """
        :type deck: List[int]
        :rtype: bool
        """
        def gcd(x, y):
            if x > y:
                return gcd(y,x)
            if x == 0:
                return y
            return gcd( y%x,x)
        from collections import Counter
        if not deck:
            return False
        cnts = Counter(deck)
        ks = list(cnts.keys())
        if len(ks) < 2:
            return cnts[ks[0]] >1
        g = 0
        for v in cnts.values():
            g = gcd(g, v)
            if g==1:
                return False
        return True