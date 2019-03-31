class Solution {
public:
    int numEnclaves(vector<vector<int>>& A) {
        int m=A.size(), n=A[0].size();
        for(int i=0;i<n;++i){
            if(A[0][i]) dfs(A,0,i,m,n);
            if(A[m-1][i]) dfs(A,m-1,i,m,n);
        }
        for(int i=0;i<m;++i){
            if(A[i][0]) dfs(A,i,0,m,n);
            if(A[i][n-1]) dfs(A,i,n-1,m,n);
        }
        int res=0;
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(A[i][j]) ++res;
            }
        }
        return res;
    }
    void dfs(vector<vector<int>>& A,int x,int y,const int m,const int n){
        if(x<0||y<0||x>=m||y>=n||A[x][y]==0) return;
        A[x][y]=0;
        dfs(A,x-1,y,m,n);
        dfs(A,x,y-1,m,n);
        dfs(A,x+1,y,m,n);
        dfs(A,x,y+1,m,n);
    }
};