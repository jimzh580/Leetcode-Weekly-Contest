class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        set<int> st;
        for(int n:A){
            if(st.find(n)!=st.end()) return n;
            else st.insert(n);
        }
        return -1;
    }
};
