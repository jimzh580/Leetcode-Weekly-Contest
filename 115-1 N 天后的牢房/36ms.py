def change(a):
    ans = [0] * len(a)
    for i in range(1, len(a)-1):
        if a[i-1] == a[i+1]:
            ans[i] = 1
        else:
            ans[i] = 0
    return tuple(ans)


class Solution(object):
    def prisonAfterNDays(self, cells, N):
        """
        :type cells: List[int]
        :type N: int
        :rtype: List[int]
        """
        memo = dict()
        cells = tuple(cells)
        l = list()
        memo[cells] = 0
        l.append(cells)
        for i in xrange(N):
            cells = change(cells)
            if cells in memo:
                last = memo[cells]
                circle = i+1-last
                rest = (N - i - 1) % circle
                return list(l[last + rest])
            else:
                memo[cells] = i+1
                l.append(cells)
        return list(cells)