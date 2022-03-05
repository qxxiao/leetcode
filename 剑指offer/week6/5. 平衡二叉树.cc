// https://www.acwing.com/problem/content/description/68/

#include <iostream>
using namespace std;
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
    bool ans = true;
    bool isBalanced(TreeNode *root)
    {

        dfs(root);
        return ans;
    }

    int dfs(TreeNode *root)
    {
        if (!root)
            return 0;
        int left = dfs(root->left);
        int right = dfs(root->right);
        if (left > right + 1 || right > left + 1)
            ans = false;
        return max(left, right) + 1;
    }
};