class Solution {
public:
  vector<int> prevPermOpt1(vector<int>& A) {
    int N = A.size();
    int pos1 = -1;
    for (int i = N - 2; i >= 0; i--) {
      if (A[i]> A[i+1]) {
        pos1 = i;
        break;
      }
    }
    if (pos1 != -1) {
      for (int i = N - 1; i >= 0; i--) {
        if (A[i] < A[pos1]) {
          swap(A[i], A[pos1]);
          break;
        }
      }
    }
    return A;
  }
};