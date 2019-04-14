class Solution {
public:
    int longestArithSeqLength(vector<int>& A) {
        int i, j, k, n, d, ans = 1;
        n = A.size();
        vector<map<int, int>> count(n);
        for (j = 1; j < n; ++j) {
            for (i = 0; i < j; ++i) {
                d = A[j] - A[i];
                count[j][d] = count[i][d] + 1;
                ans = max(ans, count[j][d]);
            }
        }
        return ans + 1;
    }
};