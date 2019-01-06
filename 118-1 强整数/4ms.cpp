class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        vector<int> res;
        unordered_set<int> m;
        if(x==1 || y==1){
            if(x==1 && y==1){
                if(2<=bound) res.push_back(2);
            }else if(x==1){
                for(int j=1;j+1<=bound;j*=y){
                    res.push_back(j+1);
                }
            }else if(y==1){
                for(int i=1;i+1<=bound;i*=x){
                    res.push_back(i+1);
                }
            }
            return res;
        }
        for(int i=1;i<=bound;i*=x){
            for(int j=1;i+j<=bound;j*=y){
                if(m.find(i+j)==m.end()){
                    res.push_back(i+j);
                    m.insert(i+j);
                }
            }
        }
        return res;
    }
};
