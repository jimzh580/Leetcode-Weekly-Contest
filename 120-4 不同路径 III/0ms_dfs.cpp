class Solution {
    bool visit[20][20];
    int ans;
    int n;
    int hei;
    int wid;
    vector<vector<int>> grid;
    void dfs(int r, int c, int l){
        if(grid[r][c] == 2){
            if(l == n)
                ans++;
            return;
        }
        if(l == n)
            return;
        if(grid[r][c] == -1)
            return;
        
        int del[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        for(int k = 0;k < 4;k++){
            int nr = r + del[k][0];
            int nc = c + del[k][1];
            if(nr >= hei || nr < 0 || nc >= wid || nc < 0)
                continue;
            if(visit[nr][nc])
                continue;
            visit[nr][nc] = true;
            dfs(nr, nc, l+1);
            visit[nr][nc] = false;
        }
    }
public:
    int uniquePathsIII(vector<vector<int>>& grid){
        hei = grid.size();
        wid = grid[0].size();
        memset(visit,false,sizeof(visit));
        ans = 0;
        int beginR, beginC;
        this->grid = grid;
        for(int i = 0;i < hei;i++)
            for(int j = 0;j < wid;j++)
                if(grid[i][j] == 1)
                    beginR = i, beginC = j, n++;
                else if(grid[i][j] != -1)
                    n++;
        visit[beginR][beginC] = true;
        dfs(beginR, beginC, 1);
        return ans;
    }
};
