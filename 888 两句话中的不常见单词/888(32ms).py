class Solution:
    def uncommonFromSentences(self, A, B):
        """
        :type A: str
        :type B: str
        :rtype: List[str]
        """
        res = collections.defaultdict(int)
        ret = []
        for i in A.split():
            res[i] += 1
        for i in B.split():
            res[i] += 1
        for key, value in res.items():
            if value == 1:
                ret.append(key)
        return ret