class Solution {
public:
    int brokenCalc(int X, int Y) {
        int cnt = 0;
        long long x, y;
        x = X, y = Y;
        long long gap = 1;
        while(x < y){
            x <<= 1;
            gap <<= 1;
            cnt++;
        }
        while(x != y){
            while(x-gap < y)
                gap >>= 1;
            x -= gap;
            cnt++;
        }
        return cnt;
    }
};