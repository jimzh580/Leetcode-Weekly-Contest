class Solution:
    def scoreOfParentheses(self, S):
        """
        :type S: str
        :rtype: int
        """
        l=[]
        for i in range(len(S)):
            if S[i]=='(':
                l.append('(')
            else:
                sum=0
                j=len(l)-1
                while j>=0:
                    if l[j]=='(':
                        if sum==0:
                            sum=1
                        else:
                            sum*=2
                        l.pop()
                        break
                    else:
                        sum+=l.pop()
                    j-=1
                l.append(sum)
        ans=0
        for i in l:
            ans+=i
        return ans
        
S="(()(()))"
# S='(())'
print(Solution.scoreOfParentheses('self',S))