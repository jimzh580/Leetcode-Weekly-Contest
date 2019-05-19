class Solution {
public:
    string removeDuplicates(string S) {
        int l=S.size();
        bool flag=true;
        while(flag){
            int len=l;
            string s="";
            flag=false;
            for(int i=0;i<l;){
                if(i<l-1&&S[i]==S[i+1]){
                    flag=true;
                    i+=2;
                    len-=2;
                }else{
                    s+=S[i++];
                }
            }
            S=s;
            l=len;
        }
        return S;
    }
};