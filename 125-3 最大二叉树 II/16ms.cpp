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
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        if ((root==NULL)||(root->val<val)){
            TreeNode *ls=new TreeNode(val);
            ls->val=val;ls->left=root;ls->right=NULL;
            return ls;
        }
        root->right=insertIntoMaxTree(root->right,val);
        return root;
    }
};
