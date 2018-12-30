/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
typedef long long ll;
typedef vector<int> VI;
typedef pair<int,int> PII;

#define REP(i,s,t) for(int i=(s);i<(t);i++)
#define FILL(x,v) memset(x,v,sizeof(x))

const int INF = (int)1E9;
#define MAXN 100005

map< pair<TreeNode*, int>, int > dp;
class Solution {
public:
  int solve(TreeNode *x, int hasP, int must) {
    if (x == NULL) return must ? INF : 0;
    pair<TreeNode*, int> state = make_pair(x, hasP * 2 + must);
    auto it = dp.find(state);
    if (it != dp.end()) return it->second;
    int sol = INF;
    if (!must) {
      if (hasP) {
        sol = min(sol, solve(x->left, 0, 0) + solve(x->right, 0, 0));
      } else {
        sol = min(sol, solve(x->left, 0, 1) + solve(x->right, 0, 0));
        sol = min(sol, solve(x->left, 0, 0) + solve(x->right, 0, 1));
      }
    }
    sol = min(sol, solve(x->left, 1, 0) + solve(x->right, 1, 0) + 1);
    dp[state] = sol;
    return sol;
  }
  int minCameraCover(TreeNode* root) {
    dp.clear();
    return solve(root, 0, 0);
  }
};
