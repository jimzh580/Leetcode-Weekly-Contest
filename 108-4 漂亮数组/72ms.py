class Solution:
    def beautifulArray(self, N):
        """
        :type N: int
        :rtype: List[int]
        """
        if N==1:
            return [1]
        else:
            l=self.beautifulArray(N//2)
            r=self.beautifulArray(N-N//2)
            return [x*2 for x in l]+[x*2-1 for x in r]