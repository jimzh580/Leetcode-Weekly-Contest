class Solution {
public:
    set<int> s;
    set<int>::iterator it;
    int lastStoneWeightII(vector<int>& stones) {
        int n=stones.size(),m=n>>1,M=n-m,i,j,k,ans=30000;
        for(i=0;i<1<<m;i++){
            for(j=k=0;j<m;j++)
                if(i>>j&1) k+=stones[j];
                else k-=stones[j];
            s.insert(k);
        }
        for(i=0;i<1<<M;i++){
            for(j=k=0;j<M;j++)
                if(i>>j&1) k+=stones[j+m];
                else k-=stones[j+m];
            it=s.lower_bound(k);
            if(it!=s.end()) ans=min(ans,*it-k);
        }
        return ans;
    }
};