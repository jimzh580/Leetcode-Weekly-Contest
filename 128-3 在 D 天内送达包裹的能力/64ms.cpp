class Solution {
public:
    int shipWithinDays(vector<int>& weights, int D) {
        int l=0,r=accumulate(weights.begin(),weights.end(),0),ans,mid;
        ans=r;
        int maxn=0;
        for(auto i:weights) maxn=max(maxn,i);
        while(l<=r){
            mid=(l+r)/2;
            if(mid<maxn){
                l=mid+1;
                continue;
            }
            int det=1,summ=0;
            for(int i:weights){
                summ+=i;
                if(summ>mid){
                    det++;
                    summ=i;
                }
            }
            if(det<=D){
                ans=min(ans,mid);
                r=mid-1;
            }else
                l=mid+1;
        }
        return ans;
    }
};