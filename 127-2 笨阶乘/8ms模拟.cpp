class Solution {
public:
    int clumsy(int N) {
        long long rate=N, ans=0;
        int op=0;
        for (int i=N-1; i>=1; i--){
            if (op==0) rate*=i;
            if (op==1) rate/=i;
            if (op==2) { ans+=rate+i; rate=0; }
            if (op==3) rate=-i;
            op=(op+1)%4;
        }
        ans+=rate;
        return ans;
    }
};