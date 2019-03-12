class Solution {
public:
    int largestSumAfterKNegations(vector<int>& A, int K) {
        sort(A.begin(), A.end());
        int n = A.size();
        for (auto &v : A)
        {
            if (v < 0 && K > 0)
            {
                v = -v;
                K --;
            }
        }
        sort(A.begin(), A.end());
        if (K%2 == 1) A[0] = -A[0];
        int ans = 0;
        for (auto v : A)
            ans += v;
        return ans;
    }
};