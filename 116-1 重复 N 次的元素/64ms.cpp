class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        int l=A.size();
        int n=l/2;
        map<int,int> m;
        for(auto i:A){
            m[i]++;
            if(m[i]==n) return i;
        }
        return 0;
    }
};
