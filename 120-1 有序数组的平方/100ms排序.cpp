class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        if(A.empty()) return A;
        for(auto &i:A){
            i*=i;
        }
        sort(A.begin(),A.end());
        return A;
    }
};
