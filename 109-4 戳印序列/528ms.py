class Solution(object):
    def movesToStamp(self, stamp, target):
        """
        :type stamp: str
        :type target: str
        :rtype: List[int]
        """
        s = list(target)
        r = []
        c, m, n = 0, len(stamp), len(target)
        def find():
            i = j = k = 0
            while i < n:
                if s[i] == '?':
                    j += 1
                elif s[i] == stamp[j]:
                    j += 1
                    k += 1
                else:
                    i -= j
                    j = k = 0
                i += 1
                if j == m:
                    if k:
                        return i - m
                    else:
                        j -= 1
            return None

        while c < n:
            i = find()
            if i is None: return []
            r.append(i)
            for j in xrange(i, i+m):
                if s[j] != '?':
                    s[j] = '?'
                    c += 1

        return r[::-1]