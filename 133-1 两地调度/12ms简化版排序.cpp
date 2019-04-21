class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        sort(costs.begin(),costs.end(),[](vector<int>& a,vector<int>& b){
            return a[0]-a[1]<b[0]-b[1];
        });
        int N=costs.size()/2;
        int r=0;
        for(int i=0;i<N;i++) r+=costs[i][0];
        for(int j=N;j<2*N;j++) r+=costs[j][1];
        return r;
    }
};