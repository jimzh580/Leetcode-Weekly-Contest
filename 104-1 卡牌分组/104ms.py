class Solution:
    def hasGroupsSizeX(self, deck):
        """
        :type deck: List[int]
        :rtype: bool
        """
        deck.sort()
        d=1
        pre=deck[0]
        for i in range(1,len(deck)):
            if pre==deck[i]:
                d+=1
            else:
                break
        if d<2:return False
        
        for k in range(d,1,-1):
            if len(deck)%k!=0:
                continue
            flag=True
            #print(k)
            for i in range(0,len(deck),k):
                #print('--',i,i+k-1)
                for j in range(i,i+k-1):
                    if deck[j]!=deck[j+1]:
                        flag=False
                        break
                if not flag:
                    break
            if flag:return True
        return False