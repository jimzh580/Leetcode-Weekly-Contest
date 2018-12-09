class Solution {
public:
    int tallestBillboard(vector<int>& rods) {
        int sum=0;
        for(int i=0;i<rods.size();i++)sum+=rods[i];
        int f[rods.size()+4][sum+4];
        memset(f,-0x3f3f3f3f,sizeof(f));
        f[0][0]=0;
        for(int i=1;i<=rods.size();i++){
            int val=rods[i-1];
            for(int j=0;j<=sum;j++){
                if(j+val<=sum)f[i][j]=max(f[i-1][j],f[i-1][j+val]);
                if(j>=val)
                    f[i][j]=max(f[i][j],f[i-1][j-val]+val);
                else
                    f[i][j]=max(f[i][j],f[i-1][val-j]+j);
            }
        }
        if(f[rods.size()][0]>0)return f[rods.size()][0];
        else return 0;
    }
};
