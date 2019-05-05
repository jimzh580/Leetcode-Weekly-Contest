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
    TreeNode* bstToGst(TreeNode* root) {
        int ans=0;
        dfs(root,ans);
        return root;
    }
    void dfs(TreeNode* root,int &ans){
        if(!root) return;
        dfs(root->right,ans);
        ans+=root->val;
        root->val=ans;
        dfs(root->left,ans);
    }
};