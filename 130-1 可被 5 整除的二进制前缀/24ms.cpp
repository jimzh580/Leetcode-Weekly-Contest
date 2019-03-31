class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& A) {
        vector<bool> res;
        res.reserve(A.size());
        int summ=0;
        for(auto i:A){
            summ=(summ<<1)+i;
            if(summ%5==0) res.push_back(true);
            else res.push_back(false);
            summ%=5;
        }
        return res;
    }
};