class Solution(object):
    def findAndReplacePattern(self, words, pattern):
        """
        :type words: List[str]
        :type pattern: str
        :rtype: List[str]
        """
        d={}
        dd={}
        l=[]
        for i in words:
            d.clear()
            dd.clear()
            flag=True
            for j in range(len(pattern)):
                if pattern[j] in d and d[pattern[j]]!=i[j]:
                    flag=False
                    break
                if i[j] in dd and dd[i[j]]!=pattern[j]:
                    flag=False
                    break
                d[pattern[j]]=i[j]
                dd[i[j]]=pattern[j]
            if flag:l.append(i)
        return l