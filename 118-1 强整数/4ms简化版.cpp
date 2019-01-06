class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        vector<int> ans; ans.clear();
        map<int, bool> vis; vis.clear();
        
        for (int a=1; a<=bound; a*=x){
            for (int b=1; b<=bound; b*=y){
                if (a+b<=bound && !vis[a+b]){
                    vis[a+b]=true;
                    ans.push_back(a+b);
                }
                if (y==1) break;
            }
            if (x==1) break;
        }
        
        sort(ans.begin(), ans.end());
        return ans;
    }
};
