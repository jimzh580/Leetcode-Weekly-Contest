class Solution {
public:
    int m,n;
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int r0, int c0, int color) {
        m=grid.size();
        n=grid[0].size();
        vector<vector<int>> vis(m,vector<int>(n,false));
        int t=grid[r0][c0];
        vector<pair<int,int>> q{{r0,c0}};
        while(!q.empty()){
            vector<pair<int,int>> tmp;
            for(auto i:q){
                if(bound(i,grid,t)) grid[i.first][i.second]=-1;
                int x=i.first, y=i.second;
                vis[x][y]=true;
                if(x>0&&!vis[x-1][y]&&grid[x-1][y]==t) tmp.push_back({x-1,y});
                if(y>0&&!vis[x][y-1]&&grid[x][y-1]==t) tmp.push_back({x,y-1});
                if(x+1<m&&!vis[x+1][y]&&grid[x+1][y]==t) tmp.push_back({x+1,y});
                if(y+1<n&&!vis[x][y+1]&&grid[x][y+1]==t) tmp.push_back({x,y+1});
            }
            q=tmp;
        }
        for(int i=0;i<m;++i)
            for(int j=0;j<n;++j)
                if(grid[i][j]==-1)
                    grid[i][j]=color;
        return grid;
    }
    bool bound(pair<int,int> &i,vector<vector<int>>& grid,const int &t){
        int x=i.first, y=i.second;
        if(x==0||x==m-1||y==0||y==n-1)
            return true;
        if(x>0&&grid[x-1][y]>0&&grid[x-1][y]!=t) return true;
        if(y>0&&grid[x][y-1]>0&&grid[x][y-1]!=t) return true;
        if(x+1<m&&grid[x+1][y]>0&&grid[x+1][y]!=t) return true;
        if(y+1<n&&grid[x][y+1]>0&&grid[x][y+1]!=t) return true;
        return false;
    }
};