class Solution:
    def maskPII(self, S):
        """
        :type S: str
        :rtype: str
        """
        d=''
        flag=False
        for i in S:
            if '0'<=i<='9':
                flag=True
                break
        if flag:
            e=''
            for i in S:
                if '0'<=i<='9':
                    e+=i
            f=len(e)
            if f>10:
                d+='+'+(f-10)*'*'+'-***-***-'
            else:
                d+='***-***-'
            d+=(e[f-4]+e[f-3]+e[f-2]+e[f-1])
        else:
            e=''
            ma=0
            for i in range(len(S)):
                if 'a'<=S[i]<='z' or 'A'<=S[i]<='Z':
                    e+=(S[i].lower())
                else:
                    if S[i]=='@':ma=i
                    e+=S[i]
            d=e[0]+5*'*'+e[ma-1:]
        return d

S="AB@qq.com"
print(Solution.maskPII('self',S))