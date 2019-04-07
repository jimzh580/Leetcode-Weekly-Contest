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
    const int mod=1000000007;
    int sumRootToLeaf(TreeNode* root) {
        int res=0;
        dfs(res,root,0);
        return res;
    }
    void dfs(int &res,TreeNode* root,int summ){
        if(!root->left&&!root->right){
            res+=((summ<<1)+root->val)%mod;
            res%=mod;
            return;
        }
        if(root->left) dfs(res,root->left,((summ<<1)+root->val)%mod);
        if(root->right) dfs(res,root->right,((summ<<1)+root->val)%mod);
    }
};