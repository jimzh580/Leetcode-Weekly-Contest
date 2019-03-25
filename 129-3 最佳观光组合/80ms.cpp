class Solution {
public:
    int sum[50000+10];
    int maxScoreSightseeingPair(vector<int>& A) {
        memset(sum,0,sizeof(sum));
        for (int i=0;i<(int)A.size();++i){
            int num=A[i]+i;
            if (i==0) sum[0]=num;
            else sum[i]=max(sum[i-1],num);
        }
        int ans=-1;
        for (int i=1;i<(int)A.size();++i){
            if (ans==-1) ans=A[i]-i+sum[i-1];
            else ans=max(ans,A[i]-i+sum[i-1]);
        }
        return ans;
    }
};