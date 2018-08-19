class Solution:
    def decodeAtIndex(self, S, K):
        """
        :type S: str
        :type K: int
        :rtype: str
        """
        l = 0
        i = 0
        
        while l < K:#find the border
            if '0' <= S[i] <= '9':#num
                l *= int(S[i])
            else:
                l += 1
            i += 1
        i -= 1
        
        while True:
            if 'a' <= S[i] <= 'z':
                if l == K:
                    return S[i]
                else:
                    l -= 1
            else:
                l //= int(S[i])
                K %= l
                if K == 0: K = l
            i -= 1
        return None