class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        int l=barcodes.size();
        unordered_map<int,int> m;
        for(auto i:barcodes){
            m[i]++;
        }
        vector<int> res(l,0);
        vector<pair<int,int>> tmp;
        for(auto f:m){
            tmp.push_back(make_pair(f.first,f.second));
        }
        sort(tmp.begin(),tmp.end(),
             [](pair<int,int> &a,pair<int,int> &b){return a.second>b.second;});
        
        int x=0;
        for(int i=0;i<l;i+=2){
            res[i]=tmp[x].first;
            tmp[x].second--;
            if(tmp[x].second==0) x++;
        }
        for(int i=1;i<l;i+=2){
            res[i]=tmp[x].first;
            tmp[x].second--;
            if(tmp[x].second==0) x++;
        }
        return res;
    }
};