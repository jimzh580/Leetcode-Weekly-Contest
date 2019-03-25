class Solution {
public:
    int smallestRepunitDivByK(int K) {
        int sum=0;
        //111%3=[(11%3)*10+1]%3
        for (int i=1;i<=10*K;++i){
            (sum=sum*10+1)%=K;
            if (sum==0) return i;
        }
        return -1;
    }
};