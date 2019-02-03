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
    string smallestFromLeaf(TreeNode* root) {
        string res;
        if(!root) return res;
        dfs(res,root,"");
        return res;
    }
    void dfs(string &res,TreeNode *root,string path){
        char c=root->val+'a';
        path=c+path;
        if(!root->left&&!root->right){
            if(res.empty() || res>path) res=path;
            return;
        }
        if(root->left) dfs(res,root->left,path);
        if(root->right) dfs(res,root->right,path);
    }
};
