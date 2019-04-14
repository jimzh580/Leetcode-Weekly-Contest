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
    TreeNode* recoverFromPreorder(string S) {
        return dfs(S,0);
    }
    TreeNode* dfs(string &s,int depth){
        int n=0,i=0;
        for(;i<s.size()&&s[i]=='-';++i,++n);
        if(depth>n) return NULL;
        int num=0;
        for(;i<s.size()&&s[i]!='-';num=num*10+(s[i]-'0'),++i);
        TreeNode* root=new TreeNode(num);
        s=s.substr(i);
        root->left=dfs(s,depth+1);
        root->right=dfs(s,depth+1);
        return root;
    }
};