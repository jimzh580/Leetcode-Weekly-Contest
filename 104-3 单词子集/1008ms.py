class Solution:
    def wordSubsets(self, A, B):
        """
        :type A: List[str]
        :type B: List[str]
        :rtype: List[str]
        """
        from collections import Counter
        needed = {}
        for bw in B:
            bwc = Counter(bw)
            for k in bwc:
                needed[k] = max(bwc[k], needed.get(k, 0))
        res = []
        for aw in A:
            awc = Counter(aw)
            isgood = True
            for k in needed:
                if k not in awc or awc[k] < needed[k]:
                    isgood=False
                    break
            if isgood:
                res.append(aw)
        return res