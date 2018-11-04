class Solution(object):
    def shortestBridge(self, A):
        """
        :type A: List[List[int]]
        :rtype: int
        """
        rows, cols = len(A), len(A[0])
        si, sj = min((i, j) for i in xrange(rows) for j in xrange(cols) if A[i][j])
        q = set([(si, sj)])
        seen = set()
        first = set()
        while q:
            first.update(q)
            seen.update(q)
            q = set((ii, jj)
                    for i,j in q for ii, jj in [(i+1,j), (i-1,j), (i,j+1), (i,j-1)]
                    if 0 <= ii < rows and 0 <= jj < cols and A[ii][jj] and (ii, jj) not in seen)
        q = first
        d = 0
        while q:
            if any(0 <= ii < rows and 0 <= jj < cols and A[ii][jj] and (ii, jj) not in seen
                   for i,j in q for ii, jj in [(i+1,j), (i-1,j), (i,j+1), (i,j-1)]):
                return d
            seen.update(q)
            d += 1
            q = set((ii, jj)
                    for i,j in q for ii, jj in [(i+1,j), (i-1,j), (i,j+1), (i,j-1)]
                    if 0 <= ii < rows and 0 <= jj < cols and not A[ii][jj] and (ii, jj) not in seen)
  