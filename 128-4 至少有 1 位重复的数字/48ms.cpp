class Solution {
public:
    int numDupDigitsAtMostN(int N) {
        int f[11][1024],i,j,k,l,m,a[100],n,ans;//n为数位
        memset(f,0,sizeof(f));//f[数位][二进制表示的数]=各数位都不同的个数
        for(i=1;i<10;i++)f[1][1<<i]=1;
        for(i=1;i<9;i++)for(j=0;j<1024;j++)if(f[i][j])for(k=0;k<10;k++)if(!(j>>k&1))f[i+1][j|1<<k]+=f[i][j];
        ans=N;
        N++;
        for(n=0;N;N/=10)a[n++]=N%10; //取每一位上的数字
        reverse(a,a+n);
        for(i=1;i<n;i++)for(j=0;j<1024;j++)ans-=f[i][j];
        memset(f,0,sizeof(f));
        for(i=l=0,m=1;i<n;i++)
        {
            for(j=0;j<1024;j++)if(f[i][j])for(k=0;k<10;k++)if(!(j>>k&1))f[i+1][j|1<<k]+=f[i][j];
            for(j=!i;j<a[i];j++)if(!(l>>j&1))f[i+1][l|1<<j]+=m;
            if(l>>a[i]&1)m=0;
            l|=1<<a[i];
        }
        for(i=0;i<1024;i++)ans-=f[n][i];
        return ans;
    }
};