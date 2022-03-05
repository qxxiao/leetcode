// https://www.acwing.com/problem/content/67/

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
    int treeDepth(TreeNode *root)
    {

        if (!root)
            return 0;
        return max(treeDepth(root->left), treeDepth(root->right)) + 1;
    }
};