class Solution:
    def shiftingLetters(self, S, shifts):
        """
        :type S: str
        :type shifts: List[int]
        :rtype: str
        """
        d=''
        a=ord('a')
        shifts[-1]%=26
        for i in range(len(S)-2,-1,-1):
            shifts[i]+=shifts[i+1]
            shifts[i]%=26
        for i in range(len(S)):
            e=chr(a+(ord(S[i])+shifts[i])%a%26)
            d+=e
        return d
        
S="kfekcu"
shifts=[98,63,13,56,58,89]
print(Solution.shiftingLetters('self',S,shifts))