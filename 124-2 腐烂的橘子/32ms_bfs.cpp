class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        set<pair<int,int>> fresh;
        vector<pair<int,int>> bad;
        if(grid.empty()) return 0;
        int m=grid.size(), n=grid[0].size();
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(grid[i][j]==1) fresh.insert(make_pair(i,j));
                else if(grid[i][j]==2) bad.push_back(make_pair(i,j));
            }
        }
        if(fresh.empty()) return 0;
        int time=0;
        int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
        while(!fresh.empty()){
            ++time;
            vector<pair<int,int>> tmp;
            for(auto i:bad){
                for(int j=0;j<4;++j){
                    int x=i.first+dir[j][0];
                    int y=i.second+dir[j][1];
                    if(x<0||x>=m||y<0||y>=n) continue;
                    if(fresh.find(make_pair(x,y))!=fresh.end()){
                        tmp.push_back(make_pair(x,y));
                        fresh.erase(make_pair(x,y));
                    }
                }
            }
            if(tmp.empty()) return -1;
            if(fresh.empty()) return time;
            bad=tmp;
        }
        return time;
    }
};
