class Solution {
public:
    bool check(int s){
        int p=sqrt(s);
        for (int i=p-2;i<=p+2;i++) if (i*i==s) return true;
        return false;
    }
    int dfs(vector<int> a,int fr){
        if (a.size()==0) return 1;
        int ans=0;
        for (int i=0;i<a.size();i++) 
            if ((i==0)||(a[i]!=a[i-1])){
                if ((fr!=-1)&&(!check(a[i]+fr))) continue;
                vector<int> b=a;
                b.erase(b.begin()+i);
                ans+=dfs(b,a[i]);
            }
        return ans;
    }
    int numSquarefulPerms(vector<int>& a) {
        sort(a.begin(),a.end());
        return dfs(a,-1);
    }
};
