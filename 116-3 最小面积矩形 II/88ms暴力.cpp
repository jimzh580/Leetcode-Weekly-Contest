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
        // ���������㣬ȷ��һ�������Σ����ҵ���һ������ - ���������, continue
        // ������ڣ��������������
        // �Ƚ������xֵ��������ÿ��ѡ3�������3��x��ͬ��continue
        // ������С�������ʹ��һ�����������Σ���x�����һ����չ���Σ����x������x��ȣ�������yҪ��ԭx��y���󡣲��������
        bool update = false;
        sort(points.begin(), points.end(), cmp);
        for(int i=0;i<points.size();i++){
            for(int j=i+1;j<points.size();j++){
                for(int k=j+1;k<points.size();k++){
                    if(i == j && j ==k) continue;
                    // ������չ
                    // �ж�ik�Ƿ�����չ
                    vector<int> tv1 = {points[i][0]+points[k][0]-points[j][0], points[i][1]+points[k][1]-points[j][1]};
                    if((tv1[0]>points[k][0] || tv1[0]==points[k][0]&&tv1[1]>points[k][1]) && sp.count(tv1)){
                        // �ж��Ƿ�ֱ
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
                    // �ж�jk���Ƿ�����չ
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
