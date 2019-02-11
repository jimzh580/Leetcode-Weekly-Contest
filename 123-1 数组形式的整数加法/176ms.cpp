class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        if(K==0) return A;
        
        vector<int> k,res;
        while(K>0){
            k.push_back(K%10);
            K/=10;
        }
        reverse(k.begin(),k.end());
        
        int i=A.size()-1, j=k.size()-1;
        int carry=0;
        while(i>=0||j>=0){
            int ans=(i>=0?A[i]:0)+(j>=0?k[j]:0)+carry;
            res.push_back(ans%10);
            carry=ans/10;
            --i; --j;
        }
        if(carry){
            res.push_back(1);
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
