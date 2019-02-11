class Solution{
    int rt[26];
    int frt(int num){
        if(rt[num] == num)
            return num;
        else
            return rt[num] = frt(rt[num]);
    }
public:
    bool equationsPossible(vector<string>& equations){
        for(int i = 0;i < 26;i++)
            rt[i] = i;
        for(string s : equations){
            if(s[1] == '!')
                continue;
            int a = s[0]-'a';
            int b = s[3]-'a';
            if(a == b)
                continue;
            a = frt(a);
            b = frt(b);
            if(a == b)
                continue;
            rt[a] = b;
        }
        for(string s : equations){
            if(s[1] == '=')
                continue;
            int a = s[0]-'a';
            int b = s[3]-'a';
            if(a == b)
                return false;
            if(frt(a) == frt(b))
                return false;
        }
        return true;
    }
};