class Solution:
    def pushDominoes(self, dominoes):
        """
        :type dominoes: str
        :rtype: str
        """
        s=list(dominoes)
        n = len(s)
        pre = ''
        prepos = -1
        for i in range(n):
            if dominoes[i] == 'L':
                if pre == 'R':
                    K = (prepos+i+1)//2-prepos
                    for j in range(K):
                        s[prepos+j] = 'R'
                        s[i-j] = 'L'
                else:
                    for j in range(prepos+1,i+1):
                        s[j] = 'L';
                prepos = i;
                pre = 'L';
            elif s[i] == 'R':
                if pre == 'R':
                    for j in range(prepos,i):
                        s[j] = 'R';
                pre = 'R';
                prepos = i;
        if pre == 'R':
            for i in range(prepos,n):
                s[i] = 'R'
        return ''.join(s)
        
dominoes=".L.R...LR..L.."
print(Solution.pushDominoes('self',dominoes))