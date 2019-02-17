/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        if(!root) return false;
        vector<TreeNode*> r{root};
        while(!r.empty()){
            vector<TreeNode*> tmp;
            unordered_set<int> t;
            for(auto i:r){
                if(i->left&&i->right){
                    if((i->left->val==x||i->left->val==y)&&
                      (i->right->val==x||i->right->val==y)){
                        return false;
                    }
                }
                if(i->left){ tmp.push_back(i->left); t.insert(i->left->val);}
                if(i->right){ tmp.push_back(i->right); t.insert(i->right->val);}
            }
            if(t.find(x)!=t.end()&&t.find(y)!=t.end()) return true;
            r=tmp;
        }
        return false;
    }
};
