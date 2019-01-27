class Solution {
public:
    string strWithout3a3b(int A, int B) {
        string t;
        if(B>A&&A>=1){
            t.push_back('b');
            t.push_back('b');
            B-=2;
        }
        while(A!=0||B!=0){
            if(A==0){
                t.push_back('b');
                B--;
                continue;
            }
            if(B==0){
                t.push_back('a');
                A--;
                continue;
            }
            if(A==B){
                t.push_back('a');
                t.push_back('b');
                A--;
                B--;
            }else if(A>B){
                t.push_back('a');
                t.push_back('a');
                t.push_back('b');
                A-=2;
                B--;
            }else{
                t.push_back('a');
                t.push_back('b');
                t.push_back('b');
                A--;
                B-=2;
            }
        }
        return t;
    }
};
