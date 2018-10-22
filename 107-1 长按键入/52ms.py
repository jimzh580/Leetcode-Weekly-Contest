class Solution:
    def isLongPressedName(self, name, typed):
        """
        :type name: str
        :type typed: str
        :rtype: bool
        """
        if len(name)>len(typed):
            return False
        elif len(name)==len(typed):
            return name==typed
        
        i=j=0
        while i<len(name) or j<len(typed):
            if j>=len(typed) and i<len(name):
                return False
            if i<len(name) and name[i]==typed[j]:
                i+=1
                j+=1
            elif i>0 and name[i-1]==typed[j]:
                j+=1
            else:
                return False
        return True