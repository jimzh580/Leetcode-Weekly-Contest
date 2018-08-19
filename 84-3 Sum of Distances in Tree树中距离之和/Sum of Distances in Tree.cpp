class Solution {
    int n;
    vector<int> par,siz,dis,ans;
    vector<vector<int>> e;
    void dfs(int u){
        siz[u]=1;
        dis[u]=0;
        for(int v:e[u]){
            if(par[u]==v)continue;
            par[v]=u;
            dfs(v);
            siz[u]+=siz[v];
            dis[u]+=dis[v]+siz[v];
        }
    }
    void dfs2(int u){
        if(par[u]==-1)ans[u]=dis[u];
        else ans[u]=ans[par[u]]+n-2*siz[u];
        for(int v:e[u]){
            if(par[u]==v)continue;
            dfs2(v);
        }
    }
public:
    vector<int> sumOfDistancesInTree(int nodes, vector<vector<int>>& edges) {
        n=nodes;
        if(n==0)return {};
        par=vector<int>(n);
        siz=vector<int>(n);
        dis=vector<int>(n);
        ans=vector<int>(n);
        e=vector<vector<int>>(n,vector<int>());
        for(auto &edg:edges){//建立无向图
            e[edg[0]].push_back(edg[1]);
            e[edg[1]].push_back(edg[0]);
        }
        par[0]=-1;
        dfs(0);
        dfs2(0);
        return ans;
    }
};