class Solution {
public:
    int maxWidthRamp(vector<int>& A) {
        int ans=0;
        stack<pair<int,int>> sta;
        for(int i=0;i<A.size();i++){
            if(sta.empty()||(A[i]<sta.top().first)) sta.push(make_pair(A[i],i));
        }
        for(int i=A.size()-1;i>=0;i--){
            while(!sta.empty()&&A[i]>=sta.top().first){
                ans=max(ans,i-sta.top().second);
                sta.pop();
            }
        }
        return ans;
    }
};
