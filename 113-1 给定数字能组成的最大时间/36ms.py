from itertools import permutations
class Solution(object):
    def largestTimeFromDigits(self, A):
        """
        :type A: List[int]
        :rtype: str
        """
        ans=''
        for a in permutations(A):
            s=''.join(str(x) for x in a)
            if int(s[:2])<24 and int(s[2:])<60:
                ans=max(ans,s[:2]+':'+s[2:])
        return ans