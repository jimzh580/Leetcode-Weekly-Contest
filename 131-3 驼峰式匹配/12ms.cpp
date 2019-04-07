class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        int l=queries.size(),lp=pattern.size();
        vector<bool> res(l,false);
        for(int i=0;i<l;++i){
            int k=0;
            bool flag=true;
            for(auto j:queries[i]){
                if(k<lp&&pattern[k]==j) ++k;
                else if(j<='z'&&j>='a') continue;
                else{flag=false;break;}
            }
            if(k==lp&&flag) res[i]=true;
        }
        return res;
    }
};