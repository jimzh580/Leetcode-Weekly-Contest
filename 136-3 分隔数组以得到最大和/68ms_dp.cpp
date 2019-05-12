class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& A, int K) {
        int m[505][505],n=A.size(),i,j,f[505];
        for(i=0;i<n;i++)for(m[i+1][i+1]=A[i],j=i+1;j<n;j++)m[i+1][j+1]=max(m[i+1][j],A[j]);
        memset(f,0,sizeof(f));
        for(i=1;i<=n;i++)for(j=1;j<=i&&j<=K;j++)f[i]=max(f[i],f[i-j]+m[i-j+1][i]*j);
        return f[n];
    }
};