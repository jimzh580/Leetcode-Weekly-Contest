class Solution(object):
    def findAndReplacePattern(self, words, pattern):
        """
        :type words: List[str]
        :type pattern: str
        :rtype: List[str]
        """
        def match(word, pattern):
            m = {}
            for a, b in zip(word, pattern):
                if b in m:
                    if m[b] != a:
                        return False
                else:
                    m[b] = a
            return len(m) == len(set(m.values()))
        
        return [w for w in words if match(w, pattern)]