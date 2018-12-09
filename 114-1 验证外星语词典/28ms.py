class Solution(object):
    def isAlienSorted(self, words, order):
        """
        :type words: List[str]
        :type order: str
        :rtype: bool
        """
        d={x:i for i,x in enumerate(order)}
        l=len(words)
        
        def valid(s1,s2):
            ll=len(s1)
            for i in range(ll):
                if i>=len(s2) or d[s1[i]]>d[s2[i]]:
                    return False
                elif d[s1[i]]<d[s2[i]]:
                    return True
            return True
        
        for i in range(1,l):
            if not valid(words[i-1],words[i]):
                return False
        return True