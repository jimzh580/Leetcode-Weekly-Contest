class Solution {
public:
    int solve(int x, int y) {
        if (y<=x) return x-y;
        else if (y%2==1) return 1+solve(x, y+1);
        else return 1+solve(x, y/2);
    }
    
    int brokenCalc(int X, int Y) {
        return solve(X, Y);
    }
};