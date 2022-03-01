// https://www.acwing.com/problem/content/38/

//* Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
    bool isSymmetric(TreeNode *root)
    {
        if (!root)
            return true;

        return dfs(root->left, root->right);
    }

    bool dfs(TreeNode *r1, TreeNode *r2)
    {
        if (!r1 || !r2)
            return !r1 && !r2;

        if (r1->val != r2->val)
            return false;
        return dfs(r1->left, r2->right) && dfs(r1->right, r2->left);
    }
};