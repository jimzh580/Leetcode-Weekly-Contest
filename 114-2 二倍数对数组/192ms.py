class Solution(object):
    def canReorderDoubled(self, A):
        """
        :type A: List[int]
        :rtype: bool
        """
        pos=collections.defaultdict(int)
        p=[]
        neg=collections.defaultdict(int)
        n=[]
        zero=0
        for i in A:
            if i<0:
                neg[i]+=1
                n.append(i)
            elif i>0:
                pos[i]+=1
                p.append(i)
            else:
                zero+=1
        
        if zero&1 or len(p)&1 or len(n)&1:
            return False
        
        p.sort()
        n.sort()
        n=n[::-1]
        
        for i in range(len(p)):
            if pos[p[i]]==0:
                continue
            pos[p[i]]-=1
            if pos[2*p[i]]<=0:
                return False
            pos[2*p[i]]-=1
            
        for i in range(len(n)):
            if neg[n[i]]==0:
                continue
            neg[n[i]]-=1
            if neg[2*n[i]]<=0:
                return False
            neg[2*n[i]]-=1
            
        return True