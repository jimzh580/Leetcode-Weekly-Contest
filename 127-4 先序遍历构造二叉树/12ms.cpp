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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if(preorder.empty()) return NULL;
        TreeNode *root=new TreeNode(preorder[0]);
        for(int i=1;i<preorder.size();++i){
            TreeNode *p=root;
            insert(p,preorder[i]);
        }
        return root;
    }
    void insert(TreeNode *&root,int val){
        while(true){
            if(root->val>val){
                if(root->left) root=root->left;
                else{
                    root->left=new TreeNode(val);
                    break;
                }
            }
            if(root->val<val){
                if(root->right) root=root->right;
                else{
                    root->right=new TreeNode(val);
                    break;
                }
            }
        }
    }
};