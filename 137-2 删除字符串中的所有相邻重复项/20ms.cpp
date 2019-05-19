class Solution {
public:
    string removeDuplicates(string S) {
        string ans;
        int n=S.size(),i;
        for(i=0;i<n;i++)
            if(ans.empty()||ans.back()!=S[i]) ans+=S[i];
            else ans.pop_back();
        return ans;
    }
};