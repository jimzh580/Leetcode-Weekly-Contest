class Solution {
public:
    int maxTurbulenceSize(vector<int>& A) {
        if(A.empty()) return 0;
        int l=A.size();
        vector<int> up(l,1),down(l,1);
        int ans=1;
        for(int i=1;i<l;++i){
            if(A[i]>A[i-1]){
                up[i]=max(up[i],down[i-1]+1);
            }else if(A[i]<A[i-1]){
                down[i]=max(down[i],up[i-1]+1);
            }
            ans=max(ans,max(up[i],down[i]));
        }
        return ans;
    }
};
