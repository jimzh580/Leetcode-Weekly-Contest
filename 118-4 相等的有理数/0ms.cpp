class Solution {
public:
    long double A=0, B=0;
    
    long double str2ldouble(string S){
        int n=S.length();
        long double z=0, s=0, x=0;
        long double rs=1, rx=1;
        
        int state=0;
        
        for (int i=0; i<n; i++){
            if (S[i]=='.') {state=1; continue;}
            if (S[i]=='(') {state=2; continue;}
            if (S[i]==')') break;
            if (state==0){
                z=z*10.0+(S[i]-'0');
            }else if (state==1){
                rs/=10.0;
                s+=rs*(S[i]-'0');
            }else{
                rx/=10.0;
                x+=rx*(S[i]-'0');
            }
        }
        
        long double ret=z+s;
        for (int i=0; i<20; i++) ret+=rs*x, x*=rx;
        
        return ret;
    }
    
    
    bool isRationalEqual(string S, string T) {
        long double A=str2ldouble(S);
        long double B=str2ldouble(T);
        
        // printf("%.10lf\n", (double)A);
        // printf("%.10lf\n", (double)B);
        long double EPS=1e-15;
        return fabs(A-B)<EPS;
    }
};
