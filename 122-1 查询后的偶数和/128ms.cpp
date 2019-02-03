class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries) {
        vector<int> res;
        if(A.empty()||queries.empty()) return res;
        int tmp=0;
        for(auto i:A) if((i&1)==0) tmp+=i;
        int index=0,val=0;
        for(auto i:queries){
            index=i[1];
            val=i[0];
            if((A[index]&1)==0) tmp-=A[index];
            A[index]+=val;
            if((A[index]&1)==0) tmp+=A[index];
            res.push_back(tmp);
        }
        return res;
    }
};
