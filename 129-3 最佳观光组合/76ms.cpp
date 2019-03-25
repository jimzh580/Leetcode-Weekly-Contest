class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& A) {
        int mx = -10000000;
        int ans = mx;
        for(int i=1; i<A.size(); ++i) {
            mx = max(mx, A[i-1]+i-1);
            ans = max(ans, A[i]-i+mx);
        }
        return ans;
    }
};