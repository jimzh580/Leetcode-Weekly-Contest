const int MAXN = 555;
int a[MAXN], b[MAXN];
int F[MAXN][MAXN];

class Solution {
public:
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
        int n = A.size();
        int m = B.size();
        for (int i = 0; i < n; ++ i)
            a[i+1] = A[i];
        for (int j = 0; j < m; ++ j)
            b[j+1] = B[j];
        for (int i = 1; i <= n; ++ i)
            for (int j = 1; j <= m; ++ j)
                if (a[i] == b[j])
                    F[i][j] = F[i-1][j-1]+1;
                else
                    F[i][j] = max(F[i-1][j], F[i][j-1]);
        return F[n][m];
    }
};