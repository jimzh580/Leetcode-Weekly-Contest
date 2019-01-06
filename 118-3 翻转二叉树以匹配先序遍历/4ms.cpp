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
    int step=1;
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        if(root->val!=voyage[0]) return vector<int>{-1};
        vector<int> res;
        bool flag=false;
        pre(res,root,voyage,flag);
        if(!flag) return vector<int>{-1};
        return res;
    }
    void pre(vector<int> &res,TreeNode* &root,vector<int>& voyage,bool &flag){
        if(flag || step==voyage.size()){
            flag=true;
            return;
        }
        if(root->left){
            if(root->left->val!=voyage[step]){
                if(!res.empty() && root->val==res.back()) return;
                TreeNode* tmp=root->left;
                root->left=root->right;
                root->right=tmp;
                res.push_back(root->val);
                pre(res,root,voyage,flag);
            }else{
                step++;
                pre(res,root->left,voyage,flag);
            }
        }
        if(root->right){
            if(root->right->val!=voyage[step]){
                return;
            }else{
                step++;
                pre(res,root->right,voyage,flag);
            }
        }
    }
};
