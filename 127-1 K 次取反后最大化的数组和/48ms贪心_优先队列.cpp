class Solution {
public:
    int largestSumAfterKNegations(vector<int>& A, int K) {
        int res=accumulate(A.begin(),A.end(),0);
        priority_queue<int,vector<int>,greater<int>> q(A.begin(),A.end());
        int tmp=0;
        while(K--){
            tmp=q.top();
            q.pop();
            cout<<res<<endl;
            res-=2*tmp;
            q.push(-tmp);
        }
        return res;
    }
};