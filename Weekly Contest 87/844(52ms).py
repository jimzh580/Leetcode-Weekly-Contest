class Solution:
    def backspaceCompare(self, S, T):
        """
        :type S: str
        :type T: str
        :rtype: bool
        """
        s = []
        for x in S:
            if ('#' == x):
                if s:
                    s.pop()
            else:
                s += x
        t = []
        for x in T:
            if ('#' == x):
                if t:
                    t.pop()
            else:
                t += x
        # print s, t
        return ''.join(s) == ''.join(t)