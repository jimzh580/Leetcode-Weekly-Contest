class Solution(object):
    def numSpecialEquivGroups(self, A):
        """
        :type A: List[str]
        :rtype: int
        """
        d,s=set(),0
        for word in A:
            t=[0]*54
            for i in range(0,len(word),2): t[ord(word[i])-ord('a')]+=1
            for i in range(1,len(word),2): t[ord(word[i])+27-ord('a')]+=1
            t=tuple(t)
            if t not in d:
                s+=1
                d.add(t)
        return s