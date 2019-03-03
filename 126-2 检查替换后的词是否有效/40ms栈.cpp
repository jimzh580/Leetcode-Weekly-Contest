class Solution {
public:
    bool isValid(string S) {
        vector<char> m;//Ä£ÄâÕ»
        for(auto i:S){
            if(i=='c'&&m.size()>=2&&m[m.size()-1]=='b'&&m[m.size()-2]=='a'){
                m.pop_back();
                m.pop_back();
            }else
                m.push_back(i);
        }
        if(m.empty()) return true;
        return false;
    }
};
