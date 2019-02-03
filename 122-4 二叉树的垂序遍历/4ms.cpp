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
    struct Num{
        int x, y, val;
        Num(int a,int b,int c):x(a),y(b),val(c){}
        bool operator <(Num &p) {
            return (x < p.x || (x == p.x && (y > p.y || y == p.y && val < p.val)));
        }
    };
    void dfs(TreeNode* root, int x, int y, vector<Num>& num) {
        if (root == NULL) return;
        num.emplace_back(x,y,root->val);
        dfs(root->left, x - 1, y - 1, num);
        dfs(root->right, x + 1, y - 1, num);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<Num> num;
        dfs(root, 0, 0, num);
        sort(num.begin(), num.end());
        vector<vector<int>> ans;
        int i = 0, j;
        while (i < num.size()) {
            vector<int> tmp;
            j = i;
            while (j < num.size()) {
                if (num[j].x != num[i].x)
                    break;
                tmp.push_back(num[j].val);
                j++;
            }
            ans.push_back(tmp);
            i = j;
        }
        return ans;
    }
};
