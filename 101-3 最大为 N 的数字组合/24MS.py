class Solution(object):
    def atMostNGivenDigitSet(self, D, N):
        """
        :type D: List[str]
        :type N: int
        :rtype: int
        """
        pows=[1]
        ns=str(N)
        for _ in range(len(ns)):
            pows.append(pows[-1]*len(D))
        ans=0
        # too few digits
        for i in range(1,len(ns)):
            ans+=pows[i]
        # do prefixes of numbers that have the correct number of digits
        keep=1
        for i in range(len(ns)):
            keep=0
            for d in D:
                if d==ns[i]:
                    keep=1
                elif d<ns[i]:
                    # this is digit i
                    # digits i+1,...,len(ns)-1 are still free
                    ans+=pows[len(ns)-i-1]
            if keep==0: break
        if keep:
            # i.e. it's possible to get N
            ans+=1
        return ans