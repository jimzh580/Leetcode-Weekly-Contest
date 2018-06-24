class Solution:
    def mirrorReflection(self, p, q):
        """
        :type p: int
        :type q: int
        :rtype: int
        """
        curr=0
        i=1
        while True:
            curr+=q#每次y轴移动距离一样
            curr%=(2*p)
            if curr==p:#到达上边界
                if i%2:
                    return 1
                else:
                    return 2
            if curr==0:
                return 0
            i+=1

p=2
q=1
print(Solution.mirrorReflection('self',p,q))