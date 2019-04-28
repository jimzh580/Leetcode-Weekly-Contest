class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c) {
        if(a>b) swap(a,b);
        if(a>c) swap(a,c);
        if(b>c) swap(c,b);
        if(a+1==b&&b+1==c) return {0,0};
        int res1=0;
        if(a+2==b||b+2==c) res1=1;
        else res1=(b-1==a?0:1)+(b+1==c?0:1);
        return {res1,(b-1==a?0:b-1-a)+(b+1==c?0:c-b-1)};
    }
};