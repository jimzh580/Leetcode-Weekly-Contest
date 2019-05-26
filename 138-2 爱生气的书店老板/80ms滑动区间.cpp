class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        int total=0;
        int l=customers.size();
        for(int i=0;i<l;++i){
            if(!grumpy[i]) total+=customers[i];
        }
        
        int res=total;
        int tmp=0;
        for(int i=0;i<l;++i){
            if(grumpy[i]) tmp+=customers[i];
            if(i-X>=0&&grumpy[i-X]) tmp-=customers[i-X];
            res=max(res,total+tmp);
        }
        return res;
    }
};