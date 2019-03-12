class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        int l=A.size();
        int a[7]={0,0,0,0,0,0,0};
        for(int i=0;i<l;++i){
            if(A[i]==B[i]){
                a[A[i]]++;
            }else{
                a[A[i]]++;
                a[B[i]]++;
            }
        }
        int r1=-1;
        for(int i=1;i<=6;++i){
            if(a[i]>=l) r1=i;
        }
        if(r1==-1) return -1;
        int aa=0,bb=0;
        for(int i=0;i<l;++i){
            if(A[i]==B[i]) continue;
            if(A[i]==r1) ++aa;
            if(B[i]==r1) ++bb;
        }
        return min(aa,bb);
    }
};