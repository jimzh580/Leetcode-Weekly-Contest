class Solution {
public:
    string removeOuterParentheses(string S) {
        int l=S.size(),left=1,i=1,index=0;
        string res="";
        for(;i<l;++i){
            if(S[i]=='(') left++;
            else left--;
            if(left==0){
                res+=S.substr(index+1,i-index-1);
                index=i+1;
            }
        }
        return res;
    }
};