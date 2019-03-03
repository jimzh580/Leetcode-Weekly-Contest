const int INF=1e9;
int sum[110],f[110][110][110],g[110][110];
class Solution {
public:
    int i,j,k,len,l,r;
    int mergeStones(vector<int>& stones, int K) {
        int n=stones.size();
        for(i=1;i<=n;++i)for(j=1;j<=n;++j)for(k=1;k<=n;++k)f[i][j][k]=INF,g[i][j]=INF;
        for (i=1;i<=n;++i){
			f[i][i][1]=g[i][i]=0;//f[�ϲ���������][�ϲ���������][�ϲ�������]=��С�ķ�
			sum[i]=sum[i-1]+stones[i-1];//g[�ϲ���������][�ϲ���������]=��С�ķ�
		}
        for (len=2;len<=n;++len){//�ϲ��ĳ���
			for (l=1;l+len-1<=n;++l){//�ϲ���������
				r=l+len-1;//�ϲ���������
				for (k=1;k<len;++k){//�ϲ�������
					for (i=l;i<r;++i){//�����￪ʼ����
						if (k==1) f[l][r][k+1]=min(f[l][r][k+1],g[l][i]+g[i+1][r]);
						else f[l][r][k+1]=min(f[l][r][k+1],f[l][i][k]+g[i+1][r]);
					}
				}
				if (len>=K) g[l][r]=min(g[l][r],f[l][r][K]+sum[r]-sum[l-1]);//�ϲ��������Ƿ��㹻
				else g[l][r]=INF;
			}
		}
        return g[1][n]==INF?-1:g[1][n];
    }
};
