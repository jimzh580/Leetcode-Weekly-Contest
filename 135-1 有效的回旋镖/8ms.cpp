class Solution {
public:
    int det(int x1, int y1, int x2, int y2, int x3, int y3)
    {
        return x1*y2-x2*y1+x2*y3-x3*y2+x3*y1-x1*y3;
    }
    bool isBoomerang(vector<vector<int>>& p) {
        return det(p[0][0], p[0][1], p[1][0], p[1][1], p[2][0], p[2][1]) != 0;
    }
};