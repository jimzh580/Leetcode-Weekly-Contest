class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        vector<int> num(26,101);
        for(auto &i:A){
            vector<int> tmp(26,0);
            for(auto j:i) tmp[j-'a']++;
            for(int j=0;j<26;++j){
                num[j]=min(num[j],tmp[j]);
            }
        }
        vector<string> res;
        for(int j=0;j<26;++j){
            while(num[j]>0){
                string t="a";
                t[0]='a'+j;
                res.push_back(t);
                num[j]--;
            }
        }
        return res;
    }
};
