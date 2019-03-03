class Solution {
public:
    bool isValid(string S) {
        int a=0,b=0,c=0;
        for (int i=0;i<(int)S.length();++i){
            if (S[i]=='a') a++;
            else if (S[i]=='b') b++;
            else c++;
            if (a<b || b<c) return false;
        }
        if (a==b && b==c) return true;
        return false;
    }
};
