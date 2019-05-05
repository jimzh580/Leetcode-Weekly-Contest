class Solution {
public:
    vector<int> numMovesStonesII(vector<int>& a) {
        int n = a.size();
        sort(a.begin(), a.end());
        int len = 0;
        for (int i = 1; i < n; ++ i)
            len += a[i]-a[i-1]-1;
        int max_ret = max(len-(a[1]-a[0]-1), len-(a[n-1]-a[n-2]-1));
        int min_ret = max_ret;
        for (int i = 0; i < n; ++ i)
        {
            int x = a[i];
            int y = a[i]+n-1;
            if (y > a[n-1]) continue;
            int L = i;
            int R = upper_bound(a.begin(), a.end(), y)-a.begin()-1;
            int cur = (L)+(n-1-R);
            if (((L) || a[R] == y) && ((n-1-R) || a[L] == x))
                min_ret = min(min_ret, cur);
        }
        return {min_ret, max_ret};
    }
};