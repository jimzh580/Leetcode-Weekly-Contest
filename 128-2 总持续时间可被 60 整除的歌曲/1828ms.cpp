class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int res=0;
        int l=time.size();
        unordered_map<int,int> m;
        for(int i=0;i<l;++i){
            for(int j=9960;j>time[i];j-=60){
                if(m.find(j-time[i])!=m.end()) res+=m[j-time[i]];
            }
            m[time[i]]++;
        }
        return res;
    }
};