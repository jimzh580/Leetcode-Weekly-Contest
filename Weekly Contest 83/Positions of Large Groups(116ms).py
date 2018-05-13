class Solution:
    def largeGroupPositions(self, S):
        """
        :type S: str
        :rtype: List[List[int]]
        """
        d=0
        l=[]
        for i in range(len(S)):
            if i+1<len(S) and S[i]==S[i+1]:
                continue
            else:
                if i-d+1>=3:
                    l.append([d,i])
                d=i+1
        return l

S="aaabc"
print(Solution.largeGroupPositions('self', S))