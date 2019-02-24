class Solution {
public:
    vector<int> gridIllumination(int n, vector<vector<int>>& vec, vector<vector<int>>& que) {
        map<int,int> x,y,up,down;
        map<int,set<int> >lg;
        for (int i=0;i<vec.size();i++){
            x[vec[i][0]]++; y[vec[i][1]]++;//x轴和y轴方向 
            up[vec[i][0]-vec[i][1]]++; down[vec[i][0]+vec[i][1]]++;//两条斜线方向 
            lg[vec[i][0]].insert(vec[i][1]);
        }
        vector<int> ans;
        for (int i=0;i<que.size();i++){
            ans.push_back((int)(bool)(x[que[i][0]]+y[que[i][1]]+up[que[i][0]-que[i][1]]+down[que[i][0]+que[i][1]]));
            for (int px=que[i][0]-1;px<=que[i][0]+1;px++) //相邻关灯
                for (int py=que[i][1]-1;py<=que[i][1]+1;py++)
                    if (lg[px].count(py)){
                        x[px]--;y[py]--;up[px-py]--;down[px+py]--;
                        lg[px].erase(py);
                    }
        }
        return ans;
    }
};
