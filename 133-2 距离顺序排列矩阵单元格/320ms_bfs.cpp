class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        vector<vector<int>> res;
        res.reserve(R*C);
        vector<vector<int>> q{vector<int>{r0,c0}};
        bool vis[101][101];
        memset(vis,false,sizeof(vis));
        vis[r0][c0]=true;
        while(!q.empty()){
            vector<vector<int>> tmp;
            for(auto i:q){
                res.push_back(i);
                if(i[0]-1>=0&&!vis[i[0]-1][i[1]]){
                    tmp.push_back(vector<int>{i[0]-1,i[1]});
                    vis[i[0]-1][i[1]]=true;
                }
                if(i[0]+1<R&&!vis[i[0]+1][i[1]]){
                    tmp.push_back(vector<int>{i[0]+1,i[1]});
                    vis[i[0]+1][i[1]]=true;
                }
                if(i[1]-1>=0&&!vis[i[0]][i[1]-1]){
                    tmp.push_back(vector<int>{i[0],i[1]-1});
                    vis[i[0]][i[1]-1]=true;
                }
                if(i[1]+1<C&&!vis[i[0]][i[1]+1]){
                    tmp.push_back(vector<int>{i[0],i[1]+1});
                    vis[i[0]][i[1]+1]=true;
                }
            }
            q=tmp;
        }
        return res;
    }
};