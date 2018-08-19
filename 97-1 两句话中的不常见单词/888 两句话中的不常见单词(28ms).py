class Solution(object):
    def uncommonFromSentences(self, A, B):
        """
        :type A: str
        :type B: str
        :rtype: List[str]
        """
        if A==[]:return B.split()
        if B==[]:return A.split()
        l=[]
        a=A.split()
        vis=set([])
        for i in a:
            if i not in vis:
                l.append(i)
                vis.add(i)
            elif i in l:
                l.remove(i)
        b=B.split()
        for i in b:
            if i not in vis:
                l.append(i)
                vis.add(i)
            elif i in l:
                l.remove(i)
        return l