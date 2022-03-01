// https : // www.acwing.com/problem/content/23/

#include <unordered_map>
#include <vector>
using namespace std;
//* Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
    unordered_map<int, int> map;
    vector<int> pre, in;

public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        pre = preorder, in = inorder;
        for (int i = 0; i < inorder.size(); i++)
            map[inorder[i]] = i;
        return dfs(0, pre.size() - 1, 0, in.size() - 1);
    }

    TreeNode *dfs(int pl, int pr, int il, int ir)
    {
        if (pl > pr)
            return nullptr;

        TreeNode *root = new TreeNode(pre[pl]);
        int k = map[pre[pl]];
        root->left = dfs(pl + 1, pl + k - il, il, k - 1);
        root->right = dfs(pl + 1 + k - il, pr, k + 1, ir);
        return root;
    }
};