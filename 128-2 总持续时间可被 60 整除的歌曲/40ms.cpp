class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int s[60],ans=0;
        memset(s,0,sizeof(s));
        for(auto i:time){
            ans+=s[(600-i)%60];
            s[i%60]++;
        }
        return ans;
    }
};