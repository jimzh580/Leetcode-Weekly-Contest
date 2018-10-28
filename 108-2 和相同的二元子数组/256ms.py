class Solution:
    def numSubarraysWithSum(self, A, S):
        """
        :type A: List[int]
        :type S: int
        :rtype: int
        """
        B=A
        d=collections.defaultdict(int)
        d[B[0]]+=1
        ans=0
        if B[0]==S: ans+=1
            
        for i in range(1,len(B)):
            B[i]+=B[i-1]
            if B[i]==S:
                ans+=1
            if B[i]-S in d:
                ans+=d[B[i]-S]
            d[B[i]]+=1
        return ans