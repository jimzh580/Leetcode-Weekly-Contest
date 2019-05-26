class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int res=0;
        vector<int> tmp=heights;
        sort(tmp.begin(),tmp.end());
        int l=heights.size();
        for(int i=0;i<l;++i){
            if(heights[i]!=tmp[i]) res++;
        }
        return res;
    }
};