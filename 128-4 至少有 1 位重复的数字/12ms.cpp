class Solution {
public:
    //a factorial function:return a!/(b-1)!
    int fac(int a, int b){//阶乘
        int res=1;
        for(int i=a; i>a-b; --i){
            res*=i;
        }
        return res;
    }
    int avail(vector<int> mask, int x){//0的个数
        int res=0;
        for(int i=0; i<x; ++i){
            if(mask[i]==0)
                res++;
        }
        return res;
    }
    int numDupDigitsAtMostN(int N) {//主调函数
        if(N<100)
            return N/11;
        
        vector<int> digits;
        int N_=N;
        int n=0;//数位
        while(true){
            digits.push_back(N%10);
            if(N/10==0)
                break;
            N=N/10;
            n++;
        }
        reverse(digits.begin(), digits.end());//获取数位上的每一个数字
        
        //[1, 10^n)
        int sum=0;
        int pre_dup=0;
        for(int i=2; i<=n; ++i){
            int total=pow(10, i-1)-pow(10,i-2);
            int pre_not_dup=total-pre_dup;
            pre_dup=pre_dup*10+pre_not_dup*(i-1);
            sum+=pre_dup;
        }
        
        //[10^n, N]
        n++;
        vector<int> mask(10, 0);//used digits
        int not_dup=0;
        for(int i=0; i<n; ++i){
            if(i==n-1){
                not_dup+=avail(mask, digits[i]);
                mask[digits[i]]++;
                if(mask[digits[i]]<=1)
                    not_dup++;
            }
            else if(i==0){
                not_dup+=(digits[i]-1)*fac(9,n-1);
                mask[digits[i]]++;
            }
            else{
                not_dup+=avail(mask, digits[i])*fac(9-i, n-1-i);
                mask[digits[i]]++;
            }
            if(mask[digits[i]]>1)
                break;
            //cout<<not_dup<<endl;
        }
        //cout<<not_dup;
        --n;
        sum=sum+(1+N_-pow(10,n))-not_dup;
        return sum;
    }
};