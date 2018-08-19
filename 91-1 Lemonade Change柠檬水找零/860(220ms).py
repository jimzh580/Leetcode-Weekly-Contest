class Solution:
    def lemonadeChange(self, bills):
        """
        :type bills: List[int]
        :rtype: bool
        """
        a=b=0
        for i in bills:
            if i==5:
                a+=1
            elif i==10:
                if a>0:
                    a-=1
                    b+=1
                else:
                    return False
            elif i==20:
                if b>0 and a>0:
                    b-=1
                    a-=1
                elif b<=0 and a>2:
                    a-=3
                else:
                    return False
            # print(a,b)
        return True
        
bills=[5,5,5,10,5,5,10,20,20,20]
print(Solution.lemonadeChange('self',bills))