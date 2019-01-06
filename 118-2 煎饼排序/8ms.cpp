class Solution {
public:
    vector<int> pancakeSort(vector<int>& A) {
        vector<int> ans; ans.clear();
        int n=A.size();
        
        for (int x=n, p; x>=1; x--){
            for (int i=0; i<n; i++) if (A[i]==x) {p=i; break;}
            if (p+1==x) continue; // No need
            if (p!=0) {
                ans.push_back(p+1);
                reverse(A.begin(), A.begin()+p+1);   
            }
            for (int i=0; i<n; i++) if (A[i]==x) {p=i; break;}
            ans.push_back(x);
            reverse(A.begin(), A.begin()+x);
        }
        
        return ans;
    }
};
