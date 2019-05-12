class Solution {
public:
    vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) {
        unordered_map<int,unordered_set<int>> m;
        vector<int> res(N,0);
        for(auto i:paths){
            m[i[0]-1].insert(i[1]-1);
            m[i[1]-1].insert(i[0]-1);
        }
        for(int i=0;i<N;++i){
            fun(res,i,m);
        }
        return res;
    }
    void fun(vector<int> &res,int index,unordered_map<int,unordered_set<int>> &m){
        if(res[index]) return;
        vector<int> vis(5,0);
        for(auto i:m[index]){
            if(res[i]) vis[res[i]]++;
        }
        for(int i=1;i<=4;++i){
            if(vis[i]) continue;
            res[index]=i;
            return;
        }
    }
};