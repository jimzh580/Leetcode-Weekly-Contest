class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int x=-1,y=-1;
        for(int i=0;i<8;++i){
            for(int j=0;j<8;++j){
                if(board[i][j]=='R'){
                    x=i; y=j;
                    break;
                }
            }
            if(x!=-1) break;
        }
        int res=0;
        int xx=x-1,yy=y;
        while(xx>=0 && board[xx][yy]=='.') --xx;
        if(xx>=0&&board[xx][yy]=='p') ++res;
        xx=x+1;
        while(xx<8 && board[xx][yy]=='.') ++xx;
        if(xx<8&&board[xx][yy]=='p') ++res;
        xx=x; yy=y-1;
        while(yy>=0 && board[xx][yy]=='.') --yy;
        if(yy>=0&&board[xx][yy]=='p') ++res;
        yy=y+1;
        while(yy<8 && board[xx][yy]=='.') ++yy;
        if(yy<8&&board[xx][yy]=='p') ++res;
        return res;
    }
};
