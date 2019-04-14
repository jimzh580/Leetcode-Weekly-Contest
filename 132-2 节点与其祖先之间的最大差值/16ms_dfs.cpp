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
    int work(TreeNode* root,int ma,int mi)
    {
        if(root==nullptr) return 0;
        int ans=max(ma-root->val,root->val-mi);
        ma=max(ma,root->val);
        mi=min(mi,root->val);
        ans=max(ans,max(work(root->left,ma,mi),work(root->right,ma,mi)));
        return ans;
    }
    int maxAncestorDiff(TreeNode* root) {
        return work(root,-100000,100000);
    }
};