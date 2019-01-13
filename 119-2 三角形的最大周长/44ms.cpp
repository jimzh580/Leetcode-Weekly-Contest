class Solution {
public:
    int largestPerimeter(vector<int>& A) {
        sort(A.begin(), A.end());
        int n=A.size();
        int ans=0;
        for(int i=0; i<n-2; i++) {
            if (A[i]+A[i+1]>A[i+2]) {
                ans=A[i]+A[i+1]+A[i+2];
            }
        }
        return ans;
    }
};
