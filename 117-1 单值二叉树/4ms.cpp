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
    bool isUnivalTree(TreeNode* root) {
        if(!root) return false;
        int x=root->val;
        return check(root,x);
    }
    bool check(TreeNode* root,const int x){
        if(!root) return true;
        if(root->val!=x) return false;
        return check(root->left,x) && check(root->right,x);
    }
};
