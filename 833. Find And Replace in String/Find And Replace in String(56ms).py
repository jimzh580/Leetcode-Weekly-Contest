class Solution:
    def findReplaceString(self, S, indexes, sources, targets):
        """
        :type S: str
        :type indexes: List[int]
        :type sources: List[str]
        :type targets: List[str]
        :rtype: str
        """
        rep=[-1]*len(S)
        for i in range(len(indexes)): #先做标记
            if S[indexes[i]:indexes[i]+len(sources[i])]==sources[i]:
                for j in range(indexes[i],indexes[i]+len(sources[i])):
                    rep[j]=i
        ret=[]
        for i in range(len(S)):
            if rep[i]>=0:
                if i==0 or rep[i]!=rep[i-1]:
                    ret.append(targets[rep[i]])
            else:
                ret.append(S[i])
        return ''.join(ret)