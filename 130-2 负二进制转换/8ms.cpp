class Solution {
public:
    string baseNeg2(int N) {
        if(N==0) return "0";
        string res="";
        while(N!=1){
            if(abs(N)%2!=0){
                res+='1';
                N=(N-1)/(-2);
            }else  {  
                res+='0';  
                N=N/(-2);
            }
        }
        res+='1';
        reverse(res.begin(),res.end());
        return res;
    }
};