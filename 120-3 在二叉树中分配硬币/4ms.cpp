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
    //儿子节点只需值为1，多余的数往上推
    int ans;
    int solve(TreeNode *node){
        if(node == NULL)
           return 0;
        int rest = node->val - 1;
        if(node->left == NULL && node->right == NULL){
            ans += abs(rest);
            return rest;
        }
        rest += solve(node->left);
        rest += solve(node->right);
        ans += abs(rest);
        return rest;
    }
public:
    int distributeCoins(TreeNode* root) {
        ans = 0;
        solve(root);
        return ans;
    }
};
