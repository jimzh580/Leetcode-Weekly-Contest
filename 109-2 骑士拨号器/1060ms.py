class Solution(object):
    def knightDialer(self, N):
        """
        :type N: int
        :rtype: int
        """
        MOD=1000000007
        l=[[0]*10 for _ in range(N)]
        for i in range(10):
            l[0][i]=1

        d={0:[4,6],1:[6,8],2:[7,9],3:[4,8],4:[0,3,9],5:[],6:[0,1,7],7:[2,6],8:[1,3],9:[2,4]}
        res=0
        for i in range(1,N):
            for j in range(10):
                for k in d[j]:
                    l[i][j]+=l[i-1][k]
                l[i][j]%=MOD
                    
        for i in range(10):
            res+=l[N-1][i]
            res%=MOD
            
        return res