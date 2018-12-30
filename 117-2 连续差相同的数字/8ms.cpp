class Solution {
public:
    vector<int> numsSameConsecDiff(int N, int K) {
        vector<int> res;
        for(int i=0;i<=9;++i)
            dfs(N-1,K,res,i,i,1);
        return res;
    }
    void dfs(int n,const int k,vector<int> &res,int i,int pre,int step){
        if(step!=1 && i/step==0) return;
        if(n==0){
            res.push_back(i);
            return;
        }
        if(pre+k<10){
            dfs(n-1,k,res,i*10+pre+k,pre+k,step*10);
        }
        if(pre-k>=0 && pre-k!=pre+k){
            dfs(n-1,k,res,i*10+pre-k,pre-k,step*10);
        }
    }
};
