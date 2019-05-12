class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& A, int K) {
        if(A.empty()) return 0;
        int l=A.size();
        vector<vector<int>> maxn(l,vector<int>(l,0));
        int cur=0;
        for(int i=0;i<l;++i){
            cur=A[i];
            maxn[i][i]=cur;
            for(int j=i+1;j<l;++j){
                cur=max(cur,A[j]);
                maxn[i][j]=cur;
            }
        }
        
        vector<int> dp(l+1,0);
        for(int i=1;i<l;++i) dp[i]=dp[i-1]+A[i-1];
        
        for(int i=0;i<l;++i){
            for(int k=1;k<=K&&i+1-k>=0;++k){
                dp[i+1]=max(dp[i+1],dp[i+1-k]+k*maxn[i+1-k][i]);
            }
            //cout<<dp[i+1]<<endl;
        }
        return dp[l];
    }
};