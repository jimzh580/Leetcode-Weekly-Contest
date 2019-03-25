class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        long long sum=0;
        for (int i=0;i<(int)A.size();++i) sum+=A[i];
        if (sum%3==0){
            long long x=A[0];
            int cnt=0;
            for (int i=1;i<(int)A.size();++i){
                //cout<<x<<endl;
                if (x==sum/3) x=0,cnt+=1;
                x+=A[i];
            }
            if (x==sum/3) cnt+=1;
            //cout<<cnt<<endl;
            return cnt==3;
        }
        else return false;
    }
};