class Solution(object):
    def fairCandySwap(self, A, B):
        """
        :type A: List[int]
        :type B: List[int]
        :rtype: List[int]
        """
        a=sum(A)
        b=sum(B)
        if (a+b)&1:return None
        n=(a+b)//2
        da=n-a
        db={v:True for v in B}
        for i in A:
            if i+da in db:
                return [i,i+da]