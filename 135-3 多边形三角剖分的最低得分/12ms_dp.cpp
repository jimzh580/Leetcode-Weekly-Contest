class Solution {
public:
    typedef long long ll;
    ll f[55][55]={0};
    int minScoreTriangulation(vector<int>& A) {
        int n=A.size();
        for(int i=0;i<n;i++)
            for(int j=i;j<n;j++){
                if(i==j||j-i==1) f[i][j]=0;
                else f[i][j]=INT_MAX;
            }
	
        for(int i=n-1;i>=0;i--){
            for(int j=i+2;j<n;j++){
                if(j==i+2) f[i][j]=mul(A,i,i+1,i+2);
                else {
                    for(int k=i+1;k<=j-1;k++){
                        f[i][j]=min(f[i][j],f[i][k]+f[k][j]+mul(A,i,k,j));
                    }
                }
            }
        }

        return f[0][n-1];
    }
    ll mul(vector<int>& a,int x,int y,int z){
        return a[x]*a[y]*a[z];
    }
};