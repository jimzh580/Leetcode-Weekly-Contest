class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c) {
        if(a>b) swap(a,b);
        if(a>c) swap(a,c);
        if(b>c) swap(b,c);
        int max_r=(c-b-1)+(b-a-1);
        int min_r=2;
        if(c==b+1&&b==a+1) min_r=0;
        else if(c-b-1<=1||b-a-1<=1) min_r=1;
        return vector<int>{min_r,max_r};
    }
};