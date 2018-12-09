class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        if (A.size() == 0 || A[0].size() == 0) {
            return 0;
        }
        int c = 0;
        vector<int> aux(A.size(), 0);
        aux[0] = 1;
        for (int i = 0; i < A[0].size(); ++i) {
            if(isOrdered(A, i, aux)) {
                ++c;
                genAux(A, i, aux);
            }
        }
        return A[0].size() - c;
    }
private:
    bool isOrdered(vector<string>& A, int c, vector<int> aux) {
        if (A.size() < 2) {
            return true;
        }
        for (int r = 1; r < A.size(); ++r) {
            if (aux[r] == 0 && A[r][c] < A[r-1][c]) {
                return false;
            }
        }
        return true;
    }
    
    void genAux(vector<string>& A, int c, vector<int>& aux) {
        for (int r = 1; r < A.size(); ++r) {
            if (A[r][c] > A[r-1][c]) {
                aux[r] = 1;
            }
        }
    }
};