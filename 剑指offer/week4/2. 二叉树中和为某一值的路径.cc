

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
    vector<int> path;

public:
    vector<vector<int>> findPath(TreeNode *root, int sum)
    {

        if (!root || sum < 0)
            return v;
        dfs(root, sum);
        return v;
    }

    void dfs(TreeNode *root, int r)
    {
        if (!root || r < root->val) // val>=0
            return;
        path.push_back(root->val);
        r -= root->val;
        // 叶子节点
        if (!root->left && !root->right && !r)
            v.push_back(path);
        dfs(root->left, r);
        dfs(root->right, r);
        path.pop_back();
    }
};