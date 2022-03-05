

#include <vector>
using namespace std;
// * Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
    vector<vector<int>> v;

public:
    vector<vector<int>> findPath(TreeNode *root, int sum)
    {

        if (!root || sum < 0)
            return v;
        dfs(vector<int>(), root, sum);
        return v;
    }

    void dfs(vector<int> ans, TreeNode *root, int r)
    {
        if (r == root->val && !root->left && !root->right)
        {
            ans.push_back(root->val);
            v.push_back(ans);
            return;
        }
        if (r < root->val)
            return;
        if (r > root->val && !root->left && !root->right)
            return;

        if (r >= root->val)
        {
            ans.push_back(root->val);
            if (root->left)
                dfs(ans, root->left, r - root->val);
            if (root->right)
                dfs(ans, root->right, r - root->val);
        }
    }
};