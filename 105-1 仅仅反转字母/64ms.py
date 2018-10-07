class Solution:
    def reverseOnlyLetters(self, S):
        """
        :type S: str
        :rtype: str
        """
        if S=='':return ''
        l=[' ']*len(S)
        i=0
        j=len(S)-1
        while i<j:
            while i<j and not S[i].isalpha():
                l[i]=S[i]
                i+=1
            while i<j and not S[j].isalpha():
                l[j]=S[j]
                j-=1
            if i>=j:
                break
            l[i]=S[j]
            l[j]=S[i]
            i+=1
            j-=1
        l[i]=S[i]
        return ''.join(l)