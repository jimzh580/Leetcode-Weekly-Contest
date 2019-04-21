class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& A, int L, int M) {
        int N=A.size();
        vector<int> sums(N+1,0);
        for(int i=0;i<N;i++) sums[i+1]=A[i]+sums[i];
        int r=-1;
        for(int i=0;i+L<=N;i++){
            for(int j=i+L;j+M<=N;j++){
                r=max(r,sums[i+L]-sums[i]+sums[j+M]-sums[j]);
            }
            for(int j=0;j+M<=i;j++)
                r=max(r,sums[i+L]-sums[i]+sums[j+M]-sums[j]);
        }
        return r;
    }
};