class Solution {
public:
    bool isBoomerang(vector<vector<int>>& points) {
        if(points[0][0]==points[1][0]&&points[0][1]==points[1][1]) return false;
        if(points[0][0]==points[2][0]&&points[0][1]==points[2][1]) return false;
        if(points[2][0]==points[1][0]&&points[2][1]==points[1][1]) return false;
        int y1=points[1][1]-points[0][1], x1=points[1][0]-points[0][0];
        int y2=points[2][1]-points[1][1], x2=points[2][0]-points[1][0];
        int a=__gcd(y1,x1);
        int b=__gcd(y2,x2);
        if(y1/a==y2/b&&x1/a==x2/b) return false;
        return true;
    }
};