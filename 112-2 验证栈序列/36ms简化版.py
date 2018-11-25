class Solution(object):
    def validateStackSequences(self, pushed, popped):
        """
        :type pushed: List[int]
        :type popped: List[int]
        :rtype: bool
        """
        n = len(pushed)
        j = 0
        s = []
        for i in range(n):
            s += [pushed[i]]
            while j < n and s and popped[j] == s[-1]:
                s.pop()
                j += 1
        return j == n