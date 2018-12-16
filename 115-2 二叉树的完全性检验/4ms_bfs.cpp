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
    bool isCompleteTree(TreeNode* root) {
        if(!root) return true;
        vector<TreeNode*> m{root};
        bool flag=true;
        int count=1;
        while(!m.empty()){
            vector<TreeNode*> tmp;
            flag=true;
            for(auto i:m){
                if(flag && i->left) tmp.push_back(i->left);
                else if(i->left) return false;
                else flag=false;
                if(flag && i->right) tmp.push_back(i->right);
                else if(i->right) return false;
                else flag=false;
            }
            if(!tmp.empty() && m.size()!=count) return false;
            count*=2;
            m=tmp;
        }
        return true;
    }
};
