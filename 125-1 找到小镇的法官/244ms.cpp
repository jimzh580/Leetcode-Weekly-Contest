class Solution {
public:
    int findJudge(int n, vector<vector<int>>& vec) {
        bool to[1010][1010],fr[1010][1010];
        memset(to,0,sizeof(to));
        memset(fr,0,sizeof(fr));
        for (int i=0;i<vec.size();i++){//有向图
            to[vec[i][0]][vec[i][1]]=true;
            fr[vec[i][1]][vec[i][0]]=true;
        }
        for (int i=1;i<=n;i++){//判断每一位能否成为法官
            bool chk=true;
            for (int j=1;j<=n;j++) if ((i!=j)&&(to[i][j])) {chk=false;break;}//他信赖其他人
            for (int j=1;j<=n;j++) if ((i!=j)&&(!fr[i][j])) {chk=false;break;}//有人不信赖他
            if (chk) return i;
        }
        return -1;
    }
};
