class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int n = A.size();
        int a[n+2] = { 0 }, s[n+2] = { 0 };
        for (int i = 1; i <= n; ++ i)
            a[i] = 1-A[i-1];
        for (int i = 1; i <= n; ++ i)
            s[i] = s[i-1]+a[i];
        int ans = 0;
        for (int i = 1; i <= n; ++ i)
        {
            int j = lower_bound(s, s+n+1, s[i]-K)-s;
            ans = max(ans, i-j);
        }
        return ans;
    }
};
