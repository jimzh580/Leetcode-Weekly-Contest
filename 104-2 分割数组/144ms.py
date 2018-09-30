class Solution:
    def partitionDisjoint(self, A):
        """
        :type A: List[int]
        :rtype: int
        """
        if not A:
            return 0
        rightmin = [float("inf")]*len(A)
        for i in range(len(A)-1, 0, -1):
            rightmin[i-1] = min(rightmin[i], A[i])
        leftmax = -float("inf")
       # print(rightmin)
        for i in range(len(A)):
            leftmax = max(leftmax, A[i])
            if leftmax <= rightmin[i]:
                break
        return i+1