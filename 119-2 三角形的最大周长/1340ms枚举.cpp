class Solution {
public:
    int largestPerimeter(vector<int>& A) {
        sort(A.begin(),A.end());
        int l=A.size(), res=0;
        for(int i=l-1;i>=2;--i){
            for(int j=i-1;j>=1;--j){
                for(int k=j-1;A[i]+A[j]+A[k]>res&&A[i]-A[j]<A[k]&&k>=0;--k){
                    res=max(res,A[i]+A[j]+A[k]);
                }
            }
        }
        return res;
    }
};
