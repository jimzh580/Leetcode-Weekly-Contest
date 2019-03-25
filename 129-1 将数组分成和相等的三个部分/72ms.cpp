class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        long long summ=accumulate(A.begin(),A.end(),0);
        //cout<<summ<<endl;
        if(summ%3) return false;
        summ/=3;
        int l=A.size();
        //cout<<l<<endl;
        int i=0;
        for(int k=0;i<l&&k!=summ;++i){
            k+=A[i];
        }
        //cout<<i<<endl;
        if(i==l) return false;
        for(int k=0;i<l&&k!=summ;++i){
            k+=A[i];
        }
        //cout<<i<<endl;
        if(i==l) return false;
        int k=0;
        for(;i<l;++i){
            k+=A[i];
        }
        //cout<<i<<endl;
        if(k!=summ) return false;
        return true;
    }
};