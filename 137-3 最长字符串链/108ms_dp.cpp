class Solution {
public:
    int longestStrChain(vector<string>& words) {
        int n=words.size();
        vector<int> dp(n,1);
        //vector<int> pre(n,-1);
        //int ans=0,res=0;
        sort(words.begin(),words.end(),
             [](string &a,string &b){return a.size()<b.size();});
        for(int i=0;i<n;++i){
            for(int j=i+1;j<n;++j){
                if(dp[i]+1<=dp[j]) continue;
                if(valid(words[i],words[j])){
                    dp[j]=dp[i]+1;
                    /*pre[j]=i;
                    if(dp[j]>res){
                        res=dp[j];
                        ans=j;
                    }*/
                }
            }
        }
        /*while(ans!=-1){
            cout<<words[ans]<<endl;
            ans=pre[ans];
        }*/
        return *max_element(dp.begin(),dp.end());
    }
    bool valid(string &a,string &b){
        int i=0,la=a.size(),lb=b.size();
        if(lb-la>1||lb==la) return false;
        for(auto s:b){
            if(s==a[i]) ++i;
            if(i==la) return true;
        }
        return i==la;
    }
};