class Solution:
    def sumSubarrayMins(self, A):
        res = 0
        mo = int(10**9+7)
        ret1 = self.getList(A, lambda x,y: x > y)
        ret2 = self.getList(list(reversed(A)), lambda x,y: x >= y)
        # print(ret1, ret2)
        for i, a, i1, i2 in zip(range(len(A)), A, ret1, reversed(ret2)):
            res += (i1-i)*(i-(len(A)-1-i2))*a
            res %= mo
        return res
    
    def getList(self, A, cmp):
        stk = []
        ret = [-1] * len(A);
        for i, a in enumerate(A):
            while stk and cmp(stk[-1][0], a):
                ret[stk.pop()[1]] = i
            stk.append((a,i))
        while stk:
            ret[stk.pop()[1]] = len(A);
        return ret