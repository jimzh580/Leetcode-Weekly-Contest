class Solution{
public:
    int subarraysWithKDistinct(vector<int>& A, int K){
        int size = A.size();
        int hash[size+1] = {};
        int cnt = 0;
        int ans = 0;
        int l = 0, r = -1;
        int step = 1;
        while(++r < size){
            if(++hash[A[r]] == 1)
                cnt++;
            if(cnt < K)
                continue;
            if(cnt > K){
                while(cnt > K){
                    if(--hash[A[l++]] == 0)
                        cnt--;
                }
                step = 1;
            }
            if(cnt == K){
                while(hash[A[l]] > 1)
                    --hash[A[l++]], step++;
                ans += step;
            }
        }
        return ans;
    }
};