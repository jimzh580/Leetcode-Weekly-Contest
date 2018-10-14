class Solution:
    def minAddToMakeValid(self, S):
        """
        :type S: str
        :rtype: int
        """
        if S=='':return 0
        l=[]
        ans=0
        for i in S:
            if l and l[-1]=='(' and i==')':
                l.pop()
            else:
                l.append(i)
        return len(l)