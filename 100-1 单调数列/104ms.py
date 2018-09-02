class Solution(object):
    def isMonotonic(self, A):
        """
        :type A: List[int]
        :rtype: bool
        """
        return all(A[i-1] <= A[i] for i in range(1, len(A))) or all(A[i-1] >= A[i] for i in range(1, len(A)))