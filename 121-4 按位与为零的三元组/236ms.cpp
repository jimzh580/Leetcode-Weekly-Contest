class Solution {
public:
    int countTriplets(vector<int>& A) {
        vector<int> cnt(65536,0);
        for(int i=0;i<65536;i++){
            for(int n:A){
                if((i&n)==0) cnt[i]++;
            }
        }
        
        int res=0;
        for(int a:A)
            for(int b:A){
                res+=cnt[a&b];
            }
        return res;
    }
};
