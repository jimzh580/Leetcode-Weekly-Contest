class TrieNode{    
public:
    bool hasVal=false;
    vector<TrieNode*> children;
    TrieNode() : children(26,NULL){
        
    }
};

class StreamChecker {
    TrieNode * root=new TrieNode();
    vector<char> ss;
     void insert(string word) {
        TrieNode *p=root;
        for(int i=0;i<word.size();i++){
            int n=word[i]-'a';
            if(p->children[n]==NULL){
                p->children[n]=new TrieNode();
            }
            p=p->children[n];
        }
        p->hasVal=true;
    }
public:
    StreamChecker(vector<string>& words) {
         for(string w:words){
             reverse(w.begin(),w.end());
             insert(w);
         }
    }
    
    bool query(char letter) {
        ss.push_back(letter);
        TrieNode *p=root;
        for(int i=ss.size()-1;i>=0&&i+2000>=ss.size();i--){
            int n=ss[i]-'a';
            if(p->children[n]==NULL){
                return false;
            }
            p=p->children[n];
            if(p->hasVal) return true;
        }
        return false;
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */