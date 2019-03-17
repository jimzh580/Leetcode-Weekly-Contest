class Solution {
public:
    int bitwiseComplement(int N) {
        if(N==0) return 1;
        int res=0;
        int i=1;
        while(i<=N){
            if((N&i)==0) res+=i;
            i<<=1;
        }
        return res;
    }
};