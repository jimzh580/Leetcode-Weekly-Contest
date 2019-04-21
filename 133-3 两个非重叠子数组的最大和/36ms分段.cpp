class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& A, int L, int M) {
        int res=0,l=A.size();
        vector<int> m(l+1,0);
        for(int i=0;i<l;++i){
            m[i+1]=m[i]+A[i];
        }
        for(int i=L;i<=l;++i){
            for(int j=i-L;j-M>=0;--j){
                res=max(res,m[i]-m[i-L]+m[j]-m[j-M]);
            }
            for(int j=i;j+M<=l;++j){
                res=max(res,m[i]-m[i-L]+m[j+M]-m[j]);
            }
        }
        return res;
    }
};