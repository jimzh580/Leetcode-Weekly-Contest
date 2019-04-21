static const int MAXN = 4000010; // number of nodes in AC automaton
static const int MAXM = 26; // cardinal of alphabet
int tot;
struct node{
    node *next[MAXM];
    node *fail;
    int val;
};
node tree[MAXN];
node *root;
node* new_node(){
    node *it = &tree[++ tot];
    for (int i = 0; i < MAXM; ++ i) it->next[i] = 0;
    it->fail = 0;
    it->val = 0;
    return it;
}
void init(){
    tot = 0;
    root = new_node();
}
node *add(string s){
    node *it = root;
    for (auto c : s){
        int x = c-'a';
        if (!it->next[x]) it->next[x] = new_node();
        it = it->next[x];
    }
    it->val = 1;
    return it;
}

void build(){
    root->fail = root;
    queue<node*> Q;
    for (int i = 0; i < MAXM; ++ i)
        if (root->next[i]){
            root->next[i]->fail = root;
            Q.push(root->next[i]);
        }
        else
            root->next[i] = root;
    while (!Q.empty()){
        node *it = Q.front();
        Q.pop();
        for (int i = 0; i < MAXM; ++ i){
            if (!it->next[i])
                it->next[i] = it->fail->next[i];
            else{
                it->next[i]->fail = it->fail->next[i];
                it->next[i]->val |= it->next[i]->fail->val;
                Q.push(it->next[i]);
            }
        }
    }
}
node *cur;
class StreamChecker {
public:
    StreamChecker(vector<string>& words) {
        init();
        for (auto &s : words)
            add(s.c_str());
        build();
        cur = root;
    }
    bool query(char letter) {
        cur = cur->next[letter-'a'];
        return cur->val;
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */