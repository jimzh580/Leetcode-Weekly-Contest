class Solution(object):
    def bagOfTokensScore(self, tokens, P):
        """
        :type tokens: List[int]
        :type P: int
        :rtype: int
        """
        if tokens==[]:return 0
        ans=0
        tokens.sort()
        if P<tokens[0]: return ans
        p1=0
        p2=len(tokens)-1
        while (p1<=p2 and P>=tokens[p1]) or (p1<p2 and P+tokens[p2]>tokens[p1] and ans>=1):
            if p1>p2:
                return ans
            if (p1<=p2 and P>=tokens[p1]):
                P-=tokens[p1]
                p1+=1
                ans+=1
            elif (p1<p2 and P+tokens[p2]>tokens[p1] and ans>=1):
                P+=tokens[p2]
                p2-=1
                ans-=1
        return ans