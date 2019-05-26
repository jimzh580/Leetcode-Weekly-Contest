class Solution {
public:
  vector<int> rearrangeBarcodes(vector<int>& B) {
    int N = B.size();
    sort(B.begin(), B.end());
    vector<int> cnt(10001);
    for (auto &b: B) cnt[b]++;
    int mB = max_element(cnt.begin(), cnt.end()) - cnt.begin();
    B.erase(remove(B.begin(), B.end(), mB), B.end());
    int L = 0;
    vector<int>  tmp(N);
    for (int S = 0; S < 2; S++) {
      for (int i = S; i < N; i+=2) {
        if (cnt[mB]) tmp[i] = mB, cnt[mB]--;
        else tmp[i] = B[L++]; 
      }
    }
    return tmp;
  }
};