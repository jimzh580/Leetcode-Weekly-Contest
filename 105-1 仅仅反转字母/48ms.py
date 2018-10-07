class Solution:
    def reverseOnlyLetters(self, S):
        """
        :type S: str
        :rtype: str
        """
        idx = [i for i,c in enumerate(S) if c.isalpha()]
        s = list(S)
        i = 0
        j = len(idx) - 1
        while i < j:
            s[idx[i]], s[idx[j]] = s[idx[j]], s[idx[i]]
            i += 1
            j -= 1
        return ''.join(s)