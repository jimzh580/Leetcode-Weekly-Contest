class Solution {
    int last(vector<int>& days,int i,int t,vector<int>& dp){
        for(int j=i-1;j>=0;j--){
            if(days[j]+t<=days[i]) return dp[j];
        }
        return 0;
    }
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(days.size());
        for(int i=0;i<days.size();i++){
            dp[i]=min(costs[2]+last(days,i,30,dp),min(costs[0]+last(days,i,1,dp),costs[1]+last(days,i,7,dp)));
        }
        return dp.back();
    }
};
