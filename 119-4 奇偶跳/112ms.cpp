class Solution {
public:
	int dp[200007][2];
	map<int, int> M;
	map<int, int> S;
    int oddEvenJumps(vector<int>& A) {
        int n=A.size();
        dp[n-1][0]=dp[n-1][1]=1;
        M[A[n-1]]=n-1;
        S[A[n-1]]=n-1;
        for(int i=n-2; i>=0; i--) {
        	//最小的比他大
        	auto it=M.lower_bound(A[i]);
        	if (it!=M.end()) {
        		dp[i][0]=dp[it->second][1];
        	}
        	//最大的比他小
        	it=S.upper_bound(A[i]);
        	if (it!=S.begin()) {
        		it--;
        		dp[i][1]=dp[it->second][0];
        	}
        	M[A[i]]=i;
        	S[A[i]]=i;
        }
        int ans=0;
        for(int i=0; i<n; i++) if (dp[i][0]) ans++;
        return ans;
    }
};
