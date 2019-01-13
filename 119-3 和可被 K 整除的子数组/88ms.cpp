class Solution {
public:
    int sum[30007];
    int subarraysDivByK(vector<int>& A, int K) {
        map<int, int> M;
        int n=A.size();      
        M[0]++;
        
        int ans=0;
        
        
        for(int i=0; i<n; i++) {
            if (i) sum[i]=sum[i-1]+A[i];
            else sum[i]=A[i];
            sum[i]=((sum[i]%K)+K)%K;
            ans+=M[sum[i]];
            M[sum[i]]++;
        }
        return ans;
    }
};
