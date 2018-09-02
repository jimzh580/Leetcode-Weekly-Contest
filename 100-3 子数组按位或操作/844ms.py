class Solution(object):
    def subarrayBitwiseORs(self, A):
        """
        :type A: List[int]
        :rtype: int
        """
        ans = set([A[0]])
        prev = set([A[0]])
        for i in range(1, len(A)):
            newSet = set(num|A[i] for num in prev)
            newSet.add(A[i])
            ans |= newSet
            prev = newSet
        # print ans
        return len(ans)