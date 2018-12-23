class Solution {
public:
    
    static int cmp(vector<int> p1, vector<int> p2){
        return p1[0] <= p2[0];
    }
    
    double minAreaFreeRect(vector<vector<int>>& points) {
        double res = 0;
        if(points.size() < 4) return res;
        set<vector<int>> sp;
        res = 1600000000;
        for(auto point : points) sp.insert(point);
        // 给定三个点，确定一个三角形，并找到另一个顶点 - 如果不存在, continue
        // 如果存在，计算面积并更新
        // 先将点根据x值进行排序，每次选3个，如果3个x相同，continue
        // 否则，用小的两个和大的一个构成三角形，向x更大的一边扩展矩形，如果x与最大的x相等，则至少y要比原x的y更大。并计算面积
        bool update = false;
        sort(points.begin(), points.end(), cmp);
        for(int i=0;i<points.size();i++){
            for(int j=i+1;j<points.size();j++){
                for(int k=j+1;k<points.size();k++){
                    if(i == j && j ==k) continue;
                    // 向外扩展
                    // 判断ik是否能扩展
                    vector<int> tv1 = {points[i][0]+points[k][0]-points[j][0], points[i][1]+points[k][1]-points[j][1]};
                    if((tv1[0]>points[k][0] || tv1[0]==points[k][0]&&tv1[1]>points[k][1]) && sp.count(tv1)){
                        // 判断是否垂直
                        if(fabs(sqrt(1.0*(tv1[1]-points[j][1])*(tv1[1]-points[j][1])+
                                     1.0*(tv1[0]-points[j][0])*(tv1[0]-points[j][0]))-
                                sqrt(1.0*(points[i][1]-points[k][1])*(points[i][1]-points[k][1])+
                                     1.0*(points[i][0]-points[k][0])*(points[i][0]-points[k][0]))) <= 0.00001){
                            double area = sqrt(1.0*(tv1[1]-points[k][1])*(tv1[1]-points[k][1])+
                                               1.0*(tv1[0]-points[k][0])*(tv1[0]-points[k][0]))*
                                sqrt(1.0*(tv1[1]-points[i][1])*(tv1[1]-points[i][1])+
                                     1.0*(tv1[0]-points[i][0])*(tv1[0]-points[i][0]));
                            res = min(res, area);
                            update = true;
                        }
                    }
                    // 判断jk边是否能扩展
                    vector<int> tv2 = {points[j][0]+points[k][0]-points[i][0], points[j][1]+points[k][1]-points[i][1]};
                    if((tv2[0]>points[k][0] || tv2[0]==points[k][0]&&tv2[1]>points[k][1]) && sp.count(tv2)){
                        if(fabs(sqrt(1.0*(tv2[1]-points[i][1])*(tv2[1]-points[i][1])+
                                     1.0*(tv2[0]-points[i][0])*(tv2[0]-points[i][0]))-
                                sqrt(1.0*(points[j][1]-points[k][1])*(points[j][1]-points[k][1])+
                                     1.0*(points[j][0]-points[k][0])*(points[j][0]-points[k][0]))) <= 0.00001){
                            double area = sqrt(1.0*(tv2[1]-points[k][1])*(tv2[1]-points[k][1])+
                                               1.0*(tv2[0]-points[k][0])*(tv2[0]-points[k][0]))*
                                sqrt(1.0*(tv2[1]-points[j][1])*(tv2[1]-points[j][1])+
                                     1.0*(tv2[0]-points[j][0])*(tv2[0]-points[j][0]));
                            res = min(res, area);
                            update = true;
                        }
                    }
                }
            }
        }
        return update ? res : 0;
    }
};
