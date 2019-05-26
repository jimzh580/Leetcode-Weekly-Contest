class Solution {
public:
    int maxSatisfied(vector<int>& c, vector<int>& g, int X) {
        int n = c.size();
        vector<int> a(n+1);
        int cnt = 0;
        for (int i = 0; i < n; ++ i)
        {
            if (!g[i]) cnt += c[i];
            a[i+1] = a[i]+c[i]*g[i];
        }
        int ans = 0;
        for (int i = 1; i <= n; ++ i)
        {
            int j = max(i-X, 0);
            ans = max(ans, cnt+a[i]-a[j]);
        }
        return ans;
    }
};