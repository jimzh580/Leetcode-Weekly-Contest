class Solution {
public:
    int search(int dp[33][33],int i,int j,int k){
        int f[33][33];memset(f,127/3,sizeof(f));//f[左坐标][合并数量] 
        for (int t=1;t<=k;t++)//合并的数量 
        for (int w=i;w<=j;w++){//开始合并的左坐标 
            if (t==1) f[w][t]=dp[i][w];
            else for (int pp=i;pp<w;pp++) f[w][t]=min(f[w][t],f[pp][t-1]+dp[pp+1][w]);//划分的地方 
        }
        return f[j][k];
    }
    int mergeStones(vector<int>& a, int k) {
        int n=a.size();
        if((n%(k-1)!=1)&&(k!=2)) return -1;
        int dp[33][33];memset(dp,127/4,sizeof(dp));//dp[左坐标][右坐标] 
        for (int ad=1;ad<=n;ad+=k-1)//合并的长度 
        for (int i=0;i<n;i++){
            int j=i+ad-1;if (j>=n) continue;
            if (i==j){
                dp[i][j]=0; 
            }else{
                dp[i][j]=search(dp,i,j,k);
                for (int t=i;t<=j;t++) dp[i][j]+=a[t];
            }
        }
        return dp[0][n-1];
    }
};
