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
    int maxAncestorDiff(TreeNode* root) {
        set<int> s;
        int res=0;
        dfs(res,root,s);
        return res;
    }
    void dfs(int &res,TreeNode* root,set<int> &s){
        if(!root) return;
        s.insert(root->val);
        if(s.size()>=2) res=max(res,*s.rbegin()-*s.begin());
        dfs(res,root->left,s);
        dfs(res,root->right,s);
        s.erase(root->val);
    }
};