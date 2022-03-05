// https://www.acwing.com/problem/content/66/

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
    TreeNode *ans;
    TreeNode *kthNode(TreeNode *root, int k)
    {

        dfs(root, k);
        return ans;
    }

    // 把答案记做全局变量更加方便
    void dfs(TreeNode *root, int &k)
    {
        if (!root)
            return; // 不会为空

        dfs(root->left, k);
        k--;
        if (!k)
        {
            ans = root;
            return;
        };
        dfs(root->right, k);
    }
};