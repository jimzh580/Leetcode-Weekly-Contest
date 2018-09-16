from math import sqrt

class Solution:
    def superpalindromesInRange(self, L, R):
        """
        :type L: str
        :type R: str
        :rtype: int
        """
        l = int(L)
        r = int(R)
        l_below = int(sqrt(l) + 0.9)
        r_upper = int(sqrt(r))
        
        l_s = str(l_below)
        l_p = min(10 ** (len(l_s) // 2), int(l_s[:(len(l_s) + 1) // 2]))
        
        r_s = str(r_upper)
        r_p = max(int(r_s[:(len(r_s) + 1) // 2]), 10 ** (len(r_s) // 2))
        count = 0
        print(l_p, r_p)
        for i in range(l_p, r_p + 1):
            i_s = str(i)
            i2 = int(i_s + i_s[-2::-1])
            #print('try', i2)
            v = i2 * i2
            if l <= v <= r:
                #print('check',v,'=',i2,'**2')
                v_s = str(v)
                if v_s == v_s[::-1]:
                    count += 1
            i3 = int(i_s + i_s[::-1])
            #print('try', i3)
            v = i3 * i3
            if l <= v <= r:
                v_s = str(v)
                #print('check',v,'=',i3,'**2')
                if v_s == v_s[::-1]:
                    count += 1
        return count