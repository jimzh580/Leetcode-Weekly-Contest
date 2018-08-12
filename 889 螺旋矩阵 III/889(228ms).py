class Solution:
    def spiralMatrixIII(self, R, C, r0, c0):
        """
        :type R: int
        :type C: int
        :type r0: int
        :type c0: int
        :rtype: List[List[int]]
        """
        ret = [[r0,c0]]
        step = 0
        while len(ret) < R*C:
            step += 1
            for i in range(step):
                c0 += 1
                if 0 <= r0 < R and 0 <= c0 < C:
                    ret.append([r0, c0])
            for i in range(step):
                r0 += 1
                if 0 <= r0 < R and 0 <= c0 < C:
                    ret.append([r0, c0])
            
            step += 1
            for i in range(step):
                c0 -= 1
                if 0 <= r0 < R and 0 <= c0 < C:
                    ret.append([r0, c0])
            for i in range(step):
                r0 -= 1
                if 0 <= r0 < R and 0 <= c0 < C:
                    ret.append([r0, c0])
        return ret