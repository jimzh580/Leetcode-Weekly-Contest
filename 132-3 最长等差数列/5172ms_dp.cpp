class Solution {
public:
    int longestArithSeqLength(vector<int>& A) {
        //int dp[2003][2003];
        //memset(dp,0,sizeof(dp));
        int n=A.size();
        vector<unordered_map<int,int>> dp;
        dp.resize(n);
        int ans = 2 ;
        for(int i=0;i<n;++i){
            for(int j=i+1;j<n;++j){
                int tmp=A[j]-A[i];
                dp[j][tmp]=max(2,max(dp[j][tmp],dp[i][tmp]+1));
                if(dp[j][tmp]>ans) ans=dp[j][tmp];
            }
        }
        return ans;
    }
};