class Solution(object):
    def numPermsDISequence(self, S):
        """
        :type S: str
        :rtype: int
        """
        # dp[number of elements in the permutation][ranking of last element in the permutation]
        li1=[1]             # previous list
        for i in range(len(S)):
            li2=[0]*(i+2)   # next list
            if S[i]=='D':
                for j in range(i+1):
                    for k in range(j+1):
                        li2[k]+=li1[j]
            else:
                for j in range(i+1):
                    for k in range(j+1,i+2):
                        li2[k]+=li1[j]
            #print(li1,li2)
            li1=[x%1000000007 for x in li2]
        return sum(li1)%1000000007