class Solution:
    def uniqueLetterString(self, S):
        """
        :type S: str
        :rtype: int
        """
        res=0
        for i in range(len(S)):
            l=i-1
            while l>=0 and S[l]!=S[i]:
                l-=1
            r=i+1
            while r<len(S) and S[r]!=S[i]:
                r+=1
            res+=(i-l)*(r-i)
        return res

S='ABA'
print(Solution.uniqueLetterString('self', S))