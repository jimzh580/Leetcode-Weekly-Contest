class Solution(object):
    def fairCandySwap(self, A, B):
        """
        :type A: List[int]
        :type B: List[int]
        :rtype: List[int]
        """
        sumA, sumB = sum(A), sum(B)
        diff = (sumA - sumB) // 2
        B = set(B)
        for a in A:
            if a - diff in B:
                return [a, a - diff]