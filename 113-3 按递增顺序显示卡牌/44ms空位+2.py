class Solution(object):
    def deckRevealedIncreasing(self, deck):
        """
        :type deck: List[int]
        :rtype: List[int]
        """
        if(deck==[]): return []
        deck.sort()
        l=len(deck)
        res=[0]*l
        i=0
        d=set(i for i in range(l))
        j=0

        while i<l-1:
            res[j]=deck[i]
            i+=1
            d.remove(j)
            t=2
            j+=1
            while t:
                if j>=l:
                    j=0
                if j in d:
                    t-=1
                    if(t): j+=1
                else:
                    j+=1
        for i in d:
            res[i]=deck[l-1]
        return res