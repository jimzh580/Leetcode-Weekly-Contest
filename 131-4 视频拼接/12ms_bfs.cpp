class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int T) {
        sort(clips.begin(),clips.end(),[](vector<int> &a,vector<int> &b){
            return a[0]!=b[0]?a[0]<b[0]:a[1]>b[1];
        });
        int l=clips.size();
        int res=0,index=0,pre=0,mx=0;
        while(index<l){
            if(mx>=T) break;
            pre=mx;
            while(index<l&&clips[index][0]<=pre){
                mx=max(mx,clips[index][1]);
                index++;
            }
            if(mx==pre) break;
            res++;
        }
        if(mx>=T) return res;
        return -1;
    }
};