class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int res=0,n=costs.size();
        sort(costs.begin(),costs.end(),
            [](vector<int>& a,vector<int> &b){return abs(a[0]-a[1])>abs(b[0]-b[1]);});
        int a=n/2,b=a;
        for(auto i:costs){
            if(a>0&&b>0){
                if(i[0]<=i[1]){
                    res+=i[0];
                    a--;
                }else{
                    res+=i[1];
                    b--;
                }
            }else if(a>0){
                res+=i[0];
                a--;
            }else if(b>0){
                res+=i[1];
                b--;
            }
            //cout<<res<<endl;
        }
        return res;
    }
};