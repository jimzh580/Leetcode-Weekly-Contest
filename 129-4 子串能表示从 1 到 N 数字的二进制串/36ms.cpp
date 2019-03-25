class Solution {
public:
    bool queryString(string S, int N) {
        int len = S.length();
        set<int> s;
        //生成所有子串，然后进行对比
        for(int j=1; j<=min(len, 30);++j) {//子串长度
            for(int i=0; i+j-1<len; ++i) {//从什么位置开始
                int num = 0;
                for(int k=i; k<i+j; ++k) {
                    num <<= 1;
                    num|=(int)(S[k]-'0');
                }
                //printf("%d\n", num);
                if(num<=N&&num>0) s.insert(num);
            }
        }
        return s.size() == N;
    }
};