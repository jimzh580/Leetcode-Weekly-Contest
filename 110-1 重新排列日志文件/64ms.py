class Solution(object):
    def reorderLogFiles(self, logs):
        """
        :type logs: List[str]
        :rtype: List[str]
        """
        def get(s):
            return (s.split(' '))[1][0]
        
        def com(s1,s2):
            x=len(s1)
            y=len(s2)
            for i in range(min(x,y)):
                if ord(s1[i])<ord(s2[i]):
                    return 1
                elif ord(s1[i])>ord(s2[i]):
                    return -1
            if x<y:
                return 1
            elif x>y:
                return -1
            else:
                return 0
        
        alpha=[i for i in logs if (get(i)).isalpha()]
        nums=[i for i in logs if (get(i)).isdigit()]
        alpha.sort(key=lambda x:' '.join(x.split(' ')[1:]),cmp=com)
        return alpha[::-1]+nums